//main.cpp

#include <utility.h>
#include <device.h>

int main(int argc, char **argv)
{
	char d_id[] = "123456";
	char m_no[] = "1234567898765432";
	Device * sim_device = new Device(d_id, m_no);
	sim_device->SetPartition();
	sim_device->DisplayDevice();
	
  Device * copyDevice = new Device(*sim_device);
  copyDevice->SetPartition();
	copyDevice->DisplayDevice();

  delete sim_device;
  delete copyDevice;
}
