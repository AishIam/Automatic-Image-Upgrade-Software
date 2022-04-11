/*******************************************************************************************
 *     FILENAME           :   Updater.h
 *     DESCRIPTION        :   Updater class definition and prototypes of functions
 *     DATE                      REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     07-04-2022					SRS			Sprint 2 implementation   
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
*****************************************************************************************/
#include <Updater.h>

/****************************************************************
FUNCTION NAME   : Updater
DESCRIPTION     : Default Constructor to the Updater class
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
Updater::Updater()
{}

/****************************************************************
FUNCTION NAME   : Updater
DESCRIPTION     : parameterized Constructor to the Updater class
PARAMETERS      : Device pointer, Header pointer, String of the confoig file name
RETURN          : nil
****************************************************************/
Updater::Updater(Device* toCopy, Header* configFile, string fname)
{
    this->targetDevice = toCopy;
    this->image = configFile;
    this->fileName = fname;
}

/****************************************************************
FUNCTION NAME   : InstallDownload
DESCRIPTION     : To copy the data from the given config file to the device specified location
PARAMETERS      : nil
RETURN          : Int, the status of the programme
****************************************************************/
int Updater::InstallDownload()
{
    if(Validate()==EXIT_FAILURE)
    {
        cout<<"Device not validated";
        return EXIT_FAILURE;
    }
    cout<<"\nValidated device\n";
    
    try{
	
    	this->deviceCopy = new Device(*targetDevice);
    	map<string, char*> deviceParts = this->targetDevice->GetPartitions();
    	string targetFile = image->GetFileType(this->fileName);
    	char * targetLocation = deviceParts[targetFile];
    	string s = this->image->GetBISize();
    	unsigned long int size = 0;
    	stringstream obj(s);
    	obj >> size;
    
    	memset(targetLocation, '\0', this->targetDevice->GetPartitionSize());
    
    	string data = "";
    	ifstream file;
    	file.open(this->fileName, ios::in);
    	if(file.is_open()){
        	string line;
        	while(getline(file,line)){
            	data += line + "\n";
        	}
        	file.close();
    	}
    
    	char* c = const_cast<char*>(data.c_str());
    	strcpy(targetLocation, c);

    	if(IsComplete(targetLocation) == false){
        	Revert();
        	cout<<"\n\nUpdation failed for "<<this->fileName<<"\n\n";
    	}
    	else{
        	cout<<"\n\nUpdation complete for "<<this->fileName<<"\n\n";
    	}
    }
    catch (std::bad_alloc & ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what();
	}
    return EXIT_SUCCESS;
}

/****************************************************************
FUNCTION NAME   : IsComplete
DESCRIPTION     : to check the data checksum with the checksum given in the file
PARAMETERS      : string, the data in the image
RETURN          : bool, the checksum are equal are not
****************************************************************/
bool Updater::IsComplete(string sent_message)
{
    int block_size = 8;
    
    string targetDataChecksum = checkSum(sent_message, block_size);
    cout<<endl<<targetDataChecksum<<endl;
    int n = targetDataChecksum.length();

    char char_array[n + 1];
 
    strcpy(char_array, targetDataChecksum.c_str());
 
    if(strcmp(char_array, this->image->GetChecksum())==0)
    {
        return true;
    }
    return false;
}

/****************************************************************
FUNCTION NAME   : Revert
DESCRIPTION     : to revert the data when the ckecksum doont match
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
void Updater::Revert()
{
    char * deviceLoacation = this->targetDevice->GetStartAddress();
    char * oldData = this->deviceCopy->GetStartAddress();
    long int size = this->deviceCopy->GetSize();

    strncpy(deviceLoacation, oldData, sizeof(char)*size);
}

/****************************************************************
FUNCTION NAME   : Validate
DESCRIPTION     : To validate the config file header details to the device details
PARAMETERS      : nil
RETURN          : int , the status of the code
****************************************************************/
int Updater::Validate()
{   

    if(strncmp(targetDevice->GetDeviceId(), image->GetDeviceID(), DEVICE_ID_SIZE)==0 && strncmp(targetDevice->GetMagicNo(), image->GetMagicNo(), MAGIC_NO_SIZE)==0)
    {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

/****************************************************************
FUNCTION NAME   : ~Updater
DESCRIPTION     : The destructor to clear all the memory
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
Updater::~Updater()
{   
    delete this->deviceCopy;
    cout<<"Update finished\n";
}

/****************************************************************
FUNCTION NAME   : Ones_complement
DESCRIPTION     : Helper function to calculate the checksum of the data
PARAMETERS      : string, the image data
RETURN          : string the ones complement of the data
****************************************************************/
string Ones_complement(string data)
{
    for (int i = 0; i < (int)data.length(); i++) {
        if (data[i] == '0')
            data[i] = '1';
        else
            data[i] = '0';
    }
 
    return data;
}

/****************************************************************
FUNCTION NAME   : CheckSum
DESCRIPTION     : To get the checksum of the data stored in device as image
PARAMETERS      : string, the image data; int, the block size
RETURN          : string, the checksum value
****************************************************************/
string checkSum(string data, int block_size)
{
    int n = data.length();
    if (n % block_size != 0) {
        int pad_size = block_size - (n % block_size);
        for (int i = 0; i < pad_size; i++) {
            data = '0' + data;
        }
    }

    string result = "";
 
    for (int i = 0; i < block_size; i++) {
        result += data[i];
    }

    for (int i = block_size; i < n; i += block_size) {

        string next_block = "";
 
        for (int j = i; j < i + block_size; j++) {
            next_block += data[j];
        }
 
        string additions = "";
        int sum = 0, carry = 0;

        for (int k = block_size - 1; k >= 0; k--) {
            sum += (next_block[k] - '0')
                   + (result[k] - '0');
            carry = sum / 2;
            if (sum == 0) {
                additions = '0' + additions;
                sum = carry;
            }
            else if (sum == 1) {
                additions = '1' + additions;
                sum = carry;
            }
            else if (sum == 2) {
                additions = '0' + additions;
                sum = carry;
            }
            else {
                additions = '1' + additions;
                sum = carry;
            }
        }

        string final = "";
 
        if (carry == 1) {
            for (int l = additions.length() - 1; l >= 0;
                 l--) {
                if (carry == 0) {
                    final = additions[l] + final;
                }
                else if (((additions[l] - '0') + carry) % 2
                         == 0) {
                    final = "0" + final;
                    carry = 1;
                }
                else {
                    final = "1" + final;
                    carry = 0;
                }
            }
 
            result = final;
        }
        else {
            result = additions;
        }
    }
 
    return Ones_complement(result);
}
 
