#define _CRT_SECURE_NO_WARNINGS
#include "apartment.h"
#include "DataLoader.h"
#include "history_structsAndConsts.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef unsigned char byte;
void commander(History_Data* hData, char* command);
void addAnApt(char** command, List* list);
List makeEmptyList();
void insertDataToEndList(List* lst, int code, char* adress, short int rooms, int price, Date sDate, Date date, Apartment* next);
Apartment* createApartment(int code, char* adress, short int rooms, int price, Date sDate, Date date, Apartment* next);
bool isEmpty(List lst);
void insertNodeToTail(List* lst, Apartment* node);
void buyAnApt(List lst, int code);
void analizeParametersForGet(int* price, int* minRooms, int* maxRooms, char** command, int* sort);
void getAnApt(int price, int minRooms, int maxRooms, int sort, char* command, List apartments);
bool conditionsAreMet(int price, int minRooms, int maxRooms, Apartment* apt);
char recognizeCommand(char* command);
char* getCommand();
void printAptsArrLowToHigh(Apartment** arr, int size);
void printAptsArrHighToLow(Apartment** arr, int size);
void mergeSortApts(Apartment** arr, int size);
void sortedMerge(Apartment** arr1, int size1, Apartment** arr2, int size2, Apartment** res);

void analizeParametersForDelete(int* hours, char** command);
void deleteAnApt(List* list, int hours);

// History funcs:
#define SHORT_HISTORY_PRINT 4
#define FULL_HISTORY_PRINT 5
HistoryEntry * createHistoryEntry(int order, char * command, HistoryEntry * prev, HistoryEntry * next);
void createEmptyHistoryList(HistoryList * hList);
void historyDataPreLoaderPrep(History_Data * hData);
void initShortTermArr(char * stArr[]);
bool isEmptyHistoryList(HistoryList * hList);
void insertToEndOfHistoryList(History_Data * hData, char * command);
void archiveQuery(History_Data * hData, char ** command);
int clasifyQueryTaskParams(char * command, int * commandNumber, char ** str1, char ** str2);
void copyString(char ** dest, char * source);
void executeFromHistory(History_Data * hData, int commandNumber);
void substituteAndRun(History_Data * hData, int commandNumber, char * str1, char * str2);
char * substituteCommandParams(History_Data * hData, char * command, char * str1, char * str2);
char * retrieveCommand(History_Data * hData, int commandNumber);
void addToArchive(History_Data * hData, char * command);
void archivePrinter(History_Data * hData, int task);
void freeHistoryData(History_Data * hData);
void freeShortTermHisArr(char ** shortTermArr);
void freeHistoryList(HistoryList * hList);

// Read Data:
void readDataFromFiles(History_Data * data);
void readApartments(List * apartments);
long int fileSize(char * filename);
void readHistory(History_Data * data);
void allocStr(char ** str, int * phS, int logS, int isFinished);


// Write Data:
void writeDataToFiles(History_Data data);
void writeApartments(List apartments);
void writeCompressedData(Apartment* apt, FILE* file);
void writeHistory(int total, char ** shortTerm_HistoryArr, HistoryList LongTerm_HistoryList);


//#define arc_print_params
