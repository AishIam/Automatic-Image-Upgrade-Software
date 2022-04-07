#include <utility.h>
#include <Header.h>

Header::Header(){}

Header::~Header(){}

//getters
char* Header::GetDeviceID(){
	return this->device_id;
}
char* Header::GetDeviceName(){
	return this->device_name;
}
char* Header::GetMagicNo(){
	return this->magic_no;
}
char* Header::GetBaseAddress(){
	return this->base_address;
}
char* Header::GetChecksum(){
	return this->checksum;
}
char* Header::GetBIAddress(){
	return this->bootImageAddress;
}
char* Header::GetBISize(){
	return this->bootImageSize;
}
char* Header::GetBIVersion(){
	return this->bootImageVersion;
}


//functions
int Header::ParseDetails(string fileName){
	
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

string Header::GetFileType(string name){
	
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

void Header::DisplayDetails(){
	cout << "Device id: " << this->device_id << endl;
	cout << "Magic No: " << this->magic_no << endl;
	cout << "Device Name: " << this->device_name << endl;
	cout << "Base Address: " << this->base_address << endl;
	cout << "Checksum: " << this->checksum << endl;
	cout << "bootImageAddress: " << this->bootImageAddress << "    bootImageSize: " 
		<< this->bootImageSize <<  "    bootImageVersion: " << bootImageVersion << endl;
}




