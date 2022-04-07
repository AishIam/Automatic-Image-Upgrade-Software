#include <Updater.h>

int Updater::Validate()
{   

    if(strncmp(targetDevice->GetDeviceId(), image->GetDeviceID(), DEVICE_ID_SIZE)==0 && strncmp(targetDevice->GetMagicNo(), image->GetMagicNo(), MAGIC_NO_SIZE)==0)
    {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

Updater::Updater()
{}
Updater::Updater(Device* toCopy, Header* configFile, string fname)
{
    this->targetDevice = toCopy;
    this->image = configFile;
    this->fileName = fname;
}
Updater::~Updater()
{   
    delete this->deviceCopy;
    cout<<"Update finished\n";
}


int Updater::InstallDownload()
{
    if(Validate()==EXIT_FAILURE)
    {
        cout<<"Device not validated";
        return EXIT_FAILURE;
    }
    cout<<"\nValidated device\n";
   
    this->deviceCopy = new Device(*this->targetDevice);
   
    map<string, char*> deviceParts = this->targetDevice->GetPartitions();
    string targetFile = image->GetFileType(this->fileName);

    char * targetLocation = deviceParts[targetFile];
    string s = this->image->GetBISize();
    unsigned long int size = 0;
    stringstream obj(s);
    obj >> size;
    
    memset(targetLocation, '\0', this->targetDevice->GetPartitionSize());
    
    ifstream indata; // indata is like cin
    char data; // variable for input value
    indata.open(this->fileName); // opens the file
    if(!indata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }
    indata >> data;
    strncpy(targetLocation, &data, 1*sizeof(char));
    while ( !indata.eof() ) 
    { 
        indata >> data;
        strcat(targetLocation, &data);
    }
    indata.close();

    if(IsComplete(targetLocation) == false)
    {
        Revert();
        cout<<"\n\nUpdation failed for "<<this->fileName<<"\n\n";
    }
    else
    {
       
        cout<<"\n\nUpdation complete for "<<this->fileName<<"\n\n";
    }
    
    
    return 0;

}

bool Updater::IsComplete(string sent_message)
{
    int block_size = 8;
    
    string targetDataChecksum = checkSum(sent_message, block_size);
    int n = targetDataChecksum.length();

    char char_array[n + 1];
 
    strcpy(char_array, targetDataChecksum.c_str());
 
    if(strcmp(char_array, this->image->GetChecksum())==0)
    {
        return true;
    }
    return false;
}
void Updater::Revert()
{
    char * deviceLoacation = this->targetDevice->GetStartAddress();
    char * oldData = this->deviceCopy->GetStartAddress();
    long int size = this->deviceCopy->GetSize();

    memcpy(deviceLoacation, oldData, sizeof(char)*size);
}




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
 