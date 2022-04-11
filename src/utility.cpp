#include "utility.h"


/*******************************************************************************
** FUNCTION NAME	:	logtrace
**
** DESCRIPTION		:	Utility function to store all kind of logs for all actions
** 				        of the running code to a specified log file
**
** ARGUMENTS		:	string criticality 
**				        string message 
**
** RETURNS		    :	None
**
*************************************************************************/
 void logtrace(string criticality, string message)
 {
	ofstream fout;
	string line;
	line = criticality + " "+ message;
	fout.open(LOGFILE, ios::app);
	
	while(fout)
	{
		fout<<line<<endl;
		break;
	}
	
	
	
	fout.close();
 }
