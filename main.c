/*
COMP20003 Assignment One (main.c)
Created by Yun-Chi Hsiao (student ID: 1074004) Aug 24th, 2020

This is the main program which executes all required processes from the task,
it is supported by read.h (read.c) and list.h (list.c).
*/

#include "read.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/******************************************************************************/

int main( int argc, char **argv) {

	struct node *list = NULL;
	struct node *item = NULL;
	size_t lineBufferLength = 0;
	FILE *dataFile = NULL;
	FILE *outputFile = NULL;
	char *dataFileName = NULL;
	char *outputFileName = NULL;
	char *fields[NUMBEROFFIELD];
	char *line = NULL;
	char **key = NULL;
	int keyCount = 0;

	key = readKey(stdin, &keyCount);

	/* Opens datafile */
	dataFileName = readDataFileName(argv);
	dataFile = openDataFile(dataFileName);

	/* Reads the header line in datafile */
	getline(&line, &lineBufferLength, dataFile);
	createField(line, fields);

	/* Creats a linked list */
	while (getline(&line, &lineBufferLength, dataFile) != EOF){
		item = createItem(line);
		list = creatList(list, item);
	}

	fclose(dataFile);

	/* Opens outputfile */
	outputFileName = readOutputFileName(argv);
	outputFile = openOutputFile(outputFileName);

	/* Searches all matched results and writing on outputfile */
	searchAll(outputFile, list, key, keyCount, fields);

	fclose(outputFile);


	/* Frees allocated memories */
	free(line);
	freeList(list, item);
	freeFields(fields);
	freeKey(key, keyCount);

	return 0;
}
