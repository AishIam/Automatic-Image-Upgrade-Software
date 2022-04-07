#ifndef __HEADER_H_
#define __HEADER_H_

#include <utility.h>

using namespace std;

class Header{
		
	public:
		Header();   //default constructor
		~Header();   //destructor
		
		
		//getters
		char* GetDeviceID();
		char* GetMagicNo();
		char* GetDeviceName();
		char* GetBaseAddress();
		char* GetChecksum();
		char* GetBIAddress();
		char* GetBISize();
		char* GetBIVersion();
	
	//functions	
	public:
		int ParseDetails(string file_name);
		void DisplayDetails();
		string GetFileType(string file_name);
		
	private:
		char device_id[DEVICE_ID_SIZE];
		char magic_no[MAGIC_NO_SIZE];
		char device_name[MAX];
		char base_address[MAX];
		char checksum[MAX];
		char bootImageAddress[MAX];
		char bootImageSize[MAX];
		char bootImageVersion[MAX];
};

#endif
