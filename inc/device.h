/*******************************************************************************************
 *     FILENAME           :   device.h
 *     DESCRIPTION        :   Device class definition and prototypes of functions
 *     DATE                NAME             REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     06-04-2022		Subhadeep Saha		SRS			Sprint 2 implementation   
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
*****************************************************************************************/
#ifndef __DEVICE_H__
#define __DEVICE_H__

//////////////HEADER FILES//////////////
#include <utility.h>

/****************************************************************
CLASS NAME      : Device
DESCRIPTION     : Class to define and create a device simulation
****************************************************************/
class Device
{
	public:
        //////Constructors//////
        Device(){}
		Device(char* d_id, char* m_no);
		Device(const Device& toCopy);

        /////Destructor/////
        ~Device();

        /////////seters////////
		unsigned long int SetHeader();
		void SetPartition();
        void SetDeviceId(char d_id[6]);
        void SetMagicNo(char m_no[16]);
        void SetSize(long int size);

        /////////geters///////
        void GetDeviceId(char *id);
        void GetMagicNo(char *no);
        long int GetSize();
        map<string, char*> GetPartitions();
        unsigned long int GetHeaderLength();

        ////////display function///////
        void DisplayDevice();
    
	private:
		char *start_address;
		long int size;
        long int partition_size;
		unsigned long int header_length;
		char Device_id[6];
		char Magic_no[16];
		map<string, char *> partitions;

};

#endif
