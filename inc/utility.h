#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <iostream>
#include <map>
#include <cstring>
#include <sstream>
#include <fstream>
#include <stdexcept>

/***************************************************
** MACROS
***************************************************/
#define DEVICE_ID_SIZE 7
#define MAGIC_NO_SIZE 16
#define MAX 100

#define LOGFILE	"../logs/aiu_execution.log"

#define FATAL	"FATAL"
#define WARN	"WARNING"
#define INFO	"INFO"
#define DEBUG   "DEBUG"

/* file access errors */
#define ERR_FILE_READ	   "[-] Error: File doesn't exist or insufficient permissions!"
#define ERR_FILE_WRITE	   "[-] Error: Can't create output file. Insufficient permissions!"

/* other errors */
#define ERR_ARG_COUNT	   "[-] Error: Minimum 3 arguments required!"
#define ERR_PARSE_DETAIL   "[-] Error: Details has not been extracted!"
#define ERR_MEM_ALLOC	   "[-] Error: Memory allocation failed!\n"


using namespace std;

/**********************************************************************
** FUNCTION PROTOTYPES
***********************************************************************/
extern void logtrace(string criticality, string message);


#endif
