
#include <utility.h>
#include <device.h>
#include <Header.h>
#include <Updater.h>

int main(int argc, char **argv)
{
	int retval = 0;
	int choice = 0;
	int j = 0;
	Header *obj[argc-1] = {0};  //array of objects of Header
	
	
	char d_id[] = "1EBH56";
	char m_no[] = "1234567898765432";
	Device * sim_device = new Device(d_id, m_no);
	sim_device->SetPartition();
	
	Updater *updtr;

	cout << "\n\n========================= AUTOMATIC IMAGE UPDATE SOFTWARE ============================" << endl << endl;
	try{
		
		if(argc < 3){
			throw invalid_argument("Less number of arguments! Enter at least 2 filenames.");
		}
		else{
			
			while(choice != 4){
				cout << "\n1. Save and display the Header details of files entered" << endl;
				cout << "2. Display Device Details" << endl;
				cout << "3. To confirm file updation" << endl;
				cout << "4. Exit" << endl << endl;
				
				cout << "Enter your choice: ";
				cin >> choice;
				
				switch(choice){
					
					case 1:
						
						cout << "\n=================== Header details of Configuration files ========================\n" << endl;
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
						break;
					case 2:
						cout << "\n=================== Device details ========================" << endl;
						sim_device->DisplayDevice();
						break;
						
					case 3:
						for(j=0; j < argc-1; j++){
							//call update function
							if(obj[j]!=NULL)
							{
								updtr = new Updater(sim_device, obj[j], argv[j+1]);
								updtr->InstallDownload();
								
							}
						}
						
						break;
						
					case 4:
						//exit
						cout << "\nExiting...." << endl;
						break;
						
					default:
						//When user enters an invalid choice
						cout << "Invalid choice!\n" << endl ;
						break;
				} //end switch

			} // end while
		}  //end else
	}  //try
	catch(invalid_argument& ex){
		cout << ex.what() << endl;
	}
	
	//deleting header objects
	for(int i = 0; i<argc-1; i++){
		delete obj[i];
	}
	
	//delete sim_device;
	//delete updtr;


	cout << "\n\n========================= CLOSING AUTOMATIC IMAGE UPDATE SOFTWARE ============================\n\n" << endl;
}
