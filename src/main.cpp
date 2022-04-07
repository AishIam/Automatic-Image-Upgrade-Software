
#include <utility.h>
#include <device.h>
#include <Header.h>

int main(int argc, char **argv)
{
	int retval = 0;
	Header *obj[argc-1] = {0};  //array of objects of Header
	
//	char d_id[] = "123456";
//	char m_no[] = "1234567898765432";
//	Device * sim_device = new Device(d_id, m_no);
//	sim_device->SetPartition();
//	sim_device->DisplayDevice();
//	
//  Device * copyDevice = new Device(*sim_device);
//  copyDevice->SetPartition();
//	copyDevice->DisplayDevice();
	try{
	
		if(argc < 3){
			throw invalid_argument("Less number of arguments!");
		}
		else{
			int j = 0;
	
			for(int i = 1; i<argc; i++){
				obj[j] = new Header();
				retval = obj[j]->ParseDetails(argv[i]);
			
				if(retval != 0){
					return -1;
				}
				else{
					obj[j]->DisplayDetails();
					cout << "\nFile Type: " << obj[j]->GetFileType(argv[i]) << endl;
				}
				j++;
			
				cout << "---------------------------------------------------------------------" << endl;
			}
		}
	}
	catch(invalid_argument& ex){
		cout << ex.what() << endl;
	}
	
	for(int i = 0; i<argc-1; i++){
		delete obj[i];
	}

//  delete sim_device;
//  delete copyDevice;
}
