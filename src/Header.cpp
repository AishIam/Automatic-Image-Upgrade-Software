#include <utility.h>
#include <Header.h>


Header::Header(){}

Header::~Header(){}

//getters
/****************************************************************
FUNCTION NAME   : GetDeviceId
DESCRIPTION     : to get Id of the device
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : char* : device id
****************************************************************/
char* Header::GetDeviceID(){
	return this->device_id;
}
/****************************************************************
FUNCTION NAME   : GetDeviceName
DESCRIPTION     : to get the name of the device
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : char* : device name
****************************************************************/
char* Header::GetDeviceName()
{
	return this->device_name;
}
/****************************************************************
FUNCTION NAME   : GetMagicNo
DESCRIPTION     : To get the magic number
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : char* : returns the magic number
****************************************************************/
char* Header::GetMagicNo()
{
	return this->magic_no;
}
/****************************************************************
FUNCTION NAME   : GetBaseAddress
DESCRIPTION     : To get the base address
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : char * : the base address
****************************************************************/
char* Header::GetBaseAddress()
{
	return this->base_address;
}
/****************************************************************
FUNCTION NAME   : GetChecksum
DESCRIPTION     : gives the checksum
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : char * : returns checksum
****************************************************************/
char* Header::GetChecksum()
{
	return this->checksum;
}
/****************************************************************
FUNCTION NAME   : GetBIAddress
DESCRIPTION     : to get the Image Address 
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : char* : image address
****************************************************************/
char* Header::GetBIAddress()
{
	return this->bootImageAddress;
}
/****************************************************************
FUNCTION NAME   : GetBISize
DESCRIPTION     : get size of boot image
PARAMETERS      : nil
FUNCTION TAG    :AIU_10
RETURN          : char* : size of boot image 
****************************************************************/
char* Header::GetBISize(){
	return this->bootImageSize;
}
/****************************************************************
FUNCTION NAME   : GetBIVersion
DESCRIPTION     : get the version of the bootimage
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : string : Image version
****************************************************************/
char* Header::GetBIVersion()
{
	return this->bootImageVersion;
}


//functions
/****************************************************************
FUNCTION NAME   : ParseDetails
DESCRIPTION     : extract details from configuration file
PARAMETERS      : string : name of the file
FUNCTION TAG    : AIU_10
RETURN          : int : status
****************************************************************/
int Header::ParseDetails(string fileName)
{
	
	ifstream file;
	file.open(fileName);
	
	if(!file){
		cout << "Cannot open file/ File not found!" << endl;
		return -1;
	}
	else{
		
		file >> this->device_id;
		file >> this->magic_no;
		file >> this->device_name;
		file >> this->checksum;
		file >> this->base_address;
		file >> this->bootImageAddress;
		file >> this->bootImageSize;
		file >> this->bootImageVersion;
		
		
		//this->device_id[7] = '\0';
		return 0;
	}
}
/****************************************************************
FUNCTION NAME   : GetFileType
DESCRIPTION     : To get type of the file 
PARAMETERS      : string : name of the file
FUNCTION TAG    : AIU_10
RETURN          : string : description
****************************************************************/
string Header::GetFileType(string name)
{
	
	string extension = name.substr(name.find_last_of(".")+1);
	
	if(extension == "KO"){
		return "kernel module";
	}
	else if(extension == "apk"){
		return "application";
	}
	else if(extension == "SO" || extension == "DLL"){
		return "libraries";
	}
	else if(extension == "FRAMEWORK"){
		return "framework level";
	}
	else if(extension == "cfg" || extension == "BAK"){
		return "file system";
	}
	else{
		return "boot image";
	}
}
/****************************************************************
FUNCTION NAME   : DisplayDetails
DESCRIPTION     : To display details about the Image
PARAMETERS      : nil
FUNCTION TAG    : AIU_10
RETURN          : nil
****************************************************************/
void Header::DisplayDetails()
{
	cout << "Device id: " << this->device_id << endl;
	cout << "Magic No: " << this->magic_no << endl;
	cout << "Device Name: " << this->device_name << endl;
	cout << "Base Address: " << this->base_address << endl;
	cout << "Checksum: " << this->checksum << endl;
	cout << "bootImageAddress: " << this->bootImageAddress << "    bootImageSize: " 
		<< this->bootImageSize <<  "    bootImageVersion: " << bootImageVersion << endl;
}








