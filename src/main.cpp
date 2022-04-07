
#include <utility.h>
#include <device.h>
#include <Header.h>
#include <Updater.h>

int main(int argc, char **argv)
{
	int retval = 0;
	
	Updater * u;
	char d_id[] = "AB185T";
	char m_no[] = "128521751983804";
	Device * sim_device = new Device(d_id, m_no);
	sim_device->SetPartition();
	
	
//  Device * copyDevice = new Device(*sim_device);
//  copyDevice->SetPartition();
//	copyDevice->DisplayDevice();
	try{
	
		if(argc < 2){
			throw invalid_argument("Less number of arguments!");
		}
		else{
			int j = 0;
			Header *obj[argc-1] = {0};  //array of objects of Header
			for(int i = 1; i<argc; i++){
				obj[j] = new Header();
				retval = obj[j]->ParseDetails(argv[i]);
				u = new Updater(sim_device, obj[j], argv[i]);
				
				u->InstallDownload();
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
	
	sim_device->DisplayDevice();
	delete sim_device;
	
}
