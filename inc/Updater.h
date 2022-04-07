#ifndef _UPDATER_H
#define _UPDATER_H

#include <utility.h>
#include <fstream>
#include <device.h>
#include <Header.h>

using std::ifstream;

class Updater{
	
	public:
		Updater();
		Updater(Device*, Header*, string);
		~Updater();
	
	public:
		int Validate();
		int InstallDownload();
		bool IsComplete(string);
		void Revert();
		
	public:
		Device * targetDevice;
		Device * deviceCopy;
		Header * image;
        string fileName;
};

extern string checkSum(string data, int block_size);
extern string Ones_complement(string data);
#endif