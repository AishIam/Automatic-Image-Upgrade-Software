#ifndef __HEADER_H_
#define __HEADER_H_

#include <utility.h>

using namespace std;

class Header{
		
	public:
		Header();   //default constructor
		~Header();   //destructor
		
		
		//getters
		char* GetDeviceID(); 			// Gets the device id that has to be synced 
		char* GetMagicNo(); 			// gets the unique magice number
		char* GetDeviceName();			// gets the name of the device
		char* GetBaseAddress();			// gets the base adddress of the boot image
		char* GetChecksum();			// gives the check which has been genrated earlier
		char* GetBIAddress();			// gives the boot image address
		char* GetBISize();				// gives the size of the boot image
		char* GetBIVersion();			// gets the version of the boot image
	
	//functions	
	public:
		int ParseDetails(string file_name);		// function to fetch details about the boot image file
		void DisplayDetails();					// function to display the details of the boot image file
		string GetFileType(string file_name);	// function to get the file type 
		
	private:
		char device_id[DEVICE_ID_SIZE];			// char array to hold device id
		char magic_no[MAGIC_NO_SIZE];			// char array to hold magic no
		char device_name[MAX];					// char array to hold device name	
		char base_address[MAX];					// char array to hold base address
		char checksum[MAX];						// char array to hold checksum value
		char bootImageAddress[MAX];				// char array to hold boot Image address
		char bootImageSize[MAX];				// char array to hold boot Image size
		char bootImageVersion[MAX];				// char array to hold boot image version
};

#endif
