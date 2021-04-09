/*
COMP20003 Assignment One (read.c)
Created by Yun-Chi Hsiao (student ID: 1074004) Aug 24th, 2020
*/

#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/******************************************************************************/

char* readDataFileName(char **argv) {

	char *dataFileName = argv[1];

	if (dataFileName == NULL) {
		printf("DataFile Name Error!");
		exit(1);
	}

	return dataFileName;
}

char* readOutputFileName(char **argv) {

	char *outputFileName = argv[2];

	if (outputFileName == NULL) {
		printf("OutputataFile Name Error!");
		exit(1);
	}

	return outputFileName;
}

FILE* openDataFile(char *dataFileName) {

	FILE *dataFile = NULL;
	dataFile = fopen(dataFileName, "r");

	if (dataFile == NULL) {
		printf("OPEN DataFile Error!");
	 	exit(1);
	}

	return dataFile;
}

FILE* openOutputFile(char *outputFileName) {

	FILE *outputFile = NULL;

	outputFile = fopen(outputFileName, "w");

	if (outputFile == NULL) {
		printf("OPEN DataFile Error!");
	 	exit(1);
	}

	return outputFile;
}

char** readKey(FILE	*stdin, int	*keyCount) {

	int i = 0;
	int keyNum = 0;
	size_t lineBufferLength = 0;
	char *line = NULL;
	char **key = (char**)malloc(sizeof(char*)*1);
	assert(key);

	while (getline(&line,&lineBufferLength,stdin) != EOF) {
		keyNum++;
		key = (char**)realloc(key, sizeof(char*)*(keyNum));
		assert(key);
		key[keyNum-1] = (char*)malloc(sizeof(char)*(strlen(line)+1));
		assert(key[keyNum-1]);
		strcpy(key[keyNum-1], line);
	}

	free(line);

	for (i = 0; i < keyNum; i++) {
		key[i][strlen(key[i])-1] = '\0';
	}

	*keyCount = keyNum;

	return key;
}

void freeKey(char **key, int keyCount) {

	int i = 0;

	for (i = 0; i < keyCount; i++){
		free(key[i]);
	}

	free(key);
}
