/*******************************************************************************************
 *     FILENAME           :   device.cpp
 *     DESCRIPTION        :   definitions of the functions given in Device class
 *     DATE                   REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     06-04-2022				SRS			Sprint 2 implementation   
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
*****************************************************************************************/


#include <Device.h>

/****************************************************************
FUNCTION NAME   : Device(Device class parameterized constructor)
DESCRIPTION     : Constructor to the Device class to initialize values
PARAMETERS      : char *: device id
                : char *:magic no
RETURN          : nil
****************************************************************/
Device::Device(char* d_id, char* m_no)
{
	long long int multiple = 120;
	long long int megi = 1024*1024;
	long int asize = (multiple*megi)/((long int) sizeof(char));
	try
	{
		
		this->start_address = new char[asize];
	}
	catch (std::bad_alloc & ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what();
	}
 	
	
    this->size = asize;
	strcpy(this->Device_id, d_id);
	strcpy(this->Magic_no, m_no);
	this->header_length = SetHeader();
}

/****************************************************************
FUNCTION NAME   : Device(Device class copy constructor)
DESCRIPTION     : Constructor to the Device class to make a deep copy
PARAMETERS      : Device : the class object
RETURN          : nil
****************************************************************/
Device::Device(const Device& toCopy)
{
    strcpy(this->Device_id, toCopy.Device_id);
    strcpy(this->Magic_no, toCopy.Magic_no);
    this->size = toCopy.size;
	try
	{
		
    	this->start_address = new char[this->size];
	}
	catch (std::bad_alloc & ba)
	{
		std::cerr << "bad_alloc caught while making device simulator : " << ba.what();
	}
	
    strncpy(this->start_address, toCopy.start_address, sizeof(char)*this->size);
	SetPartition();
}

/****************************************************************
FUNCTION NAME   : ~Device(Device class destructor)
DESCRIPTION     : Destructor to Device class to free up all memory used
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
Device:: ~Device()
{
    delete [] this->start_address;

}

/****************************************************************
FUNCTION NAME   : SetHeader
DESCRIPTION     : To set the header to the device and add the metadata
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
unsigned long int Device::SetHeader()
{
	strcpy(this->start_address, this->Device_id);
	strcpy((this->start_address+sizeof(this->Device_id)), this->Magic_no);
	return (sizeof(this->Device_id)+sizeof(this->Magic_no));
}

/****************************************************************
FUNCTION NAME   : SetPartition
DESCRIPTION     : To set the partition of the device and update the map
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
void Device::SetPartition()
{			
	long long int p_size = ((this->size - this->header_length) * sizeof(char))/6;
	
    this->partition_size = p_size;

	this->partitions["boot image"] = (this->start_address + this->header_length);
	
	this->partitions["application"] = (partitions["boot image"] + p_size);
	
	this->partitions["libraries"] = (partitions["application"] + p_size); 
	
	this->partitions["framework level"] = (partitions["libraries"] + p_size); 
	
	this->partitions["file system"] = (partitions["framework level"] + p_size);
	
	this->partitions["kernel module"] = (partitions["file system"] + p_size);
	
	//strcpy(this->partitions["kernel module"], "this is the basic initialisation");
}

void Device::SetMemory()
{
	unsigned long long int p_size = this->partition_size;
	memset(this->partitions["boot image"], '\0', p_size);
	memset(this->partitions["application"], '\0', p_size); 
	memset(this->partitions["libraries"], '\0', p_size);
	memset(this->partitions["framework level"], '\0', p_size);
	memset(this->partitions["file system"], '\0', p_size);
	memset(this->partitions["kernel module"], '\0', p_size);
}

/****************************************************************
FUNCTION NAME   : SetDeviceId
DESCRIPTION     : To set the device id
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
void Device::SetDeviceId(char d_id[6])
{
    strncpy(this->Device_id, d_id, sizeof(char)*DEVICE_ID_SIZE);

}

/****************************************************************
FUNCTION NAME   : SetMagicNo
DESCRIPTION     : To set the magic no
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
void Device::SetMagicNo(char m_no[16])
{
    strncpy(this->Magic_no, m_no, sizeof(char)*MAGIC_NO_SIZE);

}

/****************************************************************
FUNCTION NAME   : SetMagicNo
DESCRIPTION     : To set the size
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
void Device::SetSize(long int sz)
{
    this->size = sz;
}

/****************************************************************
FUNCTION NAME   : GetStartAddress
DESCRIPTION     : To get the start address
PARAMETERS      : nil
RETURN          : char *, start address
****************************************************************/
char * Device::GetStartAddress()
{
	return this->start_address;
}
/****************************************************************
FUNCTION NAME   : GetDeviceId
DESCRIPTION     : To get device id
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
char * Device::GetDeviceId()
{
    return this->Device_id;
}

/****************************************************************
FUNCTION NAME   : GetMagicNo
DESCRIPTION     : To get magic no
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
char * Device::GetMagicNo()
{
   return this->Magic_no;

}

/****************************************************************
FUNCTION NAME   : GetMagicNo
DESCRIPTION     : To get size
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
long int Device::GetSize()
{
    return this->size;
}

/****************************************************************
FUNCTION NAME   : GetPartitions
DESCRIPTION     : To get partitions from the map
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
map<string, char*> Device::GetPartitions()
{
    return this->partitions;
}

/****************************************************************
FUNCTION NAME   : GetPartitions
DESCRIPTION     : To get partitions from the map
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
unsigned long int Device::GetHeaderLength()
{
    return this->header_length;
}

/****************************************************************
FUNCTION NAME   : GetPartitionSize
DESCRIPTION     : To get partitions size
PARAMETERS      : nil
RETURN          : unsigned long int, the partition size
****************************************************************/
unsigned long int Device::GetPartitionSize()
{
	return this->partition_size;
}
/****************************************************************
FUNCTION NAME   : DisplayDevice
DESCRIPTION     : To display all the partitions in the device
PARAMETERS      : nil
RETURN          : nil
****************************************************************/
void Device::DisplayDevice()
{
	cout<< "Start of device : \t" << (void *)&this->start_address[0]<<endl;
	cout<< "application : \t\t" << (void *)this->partitions["application"]<<" : "<<this->partitions["application"]<<endl;
	cout<< "boot image : \t\t" << (void *)this->partitions["boot image"]<<" : "<<this->partitions["boot image"]<<endl;
	cout<< "libraries : \t\t" << (void *)this->partitions["libraries"]<<" : "<<this->partitions["libraries"]<<endl;
	cout<< "framework level : \t" << (void *)this->partitions["framework level"]<<" : "<<this->partitions["framework level"]<<endl;
	cout<< "file system : \t\t" << (void *)this->partitions["file system"]<<" : "<<this->partitions["file system"]<<endl;
	cout<< "kernel module : \t" << (void *)this->partitions["kernel module"]<<" : "<< this->partitions["kernel module"]<<endl;
	
	
    cout<< "End Address : \t\t"<<(void *)&(this->start_address[this->size-1])<<endl;
	cout<< "Total Length : "<<this->size<<" bytes"<<endl;
	
	
}
