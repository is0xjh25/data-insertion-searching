/*
COMP20003 Assignment One (read.h)
Created by Yun-Chi Hsiao (student ID: 1074004) Aug 24th, 2020

This is the header file for read.c.
The following functions are aim to read datafile, open the outputfile and
read the input as the keys for searching.
If any of these process fails, the program would be terminated.
The purpose of reading key here is that
the user can change the way to enter keys easily, and the format of using
searching function in list.c would simply be a string.
*/

#ifndef READH
#define READH
#include <stdio.h>

/* Opens Data File */
FILE* openDataFile(char *dataFileName);

/* Opens Output File */
FILE* openOutputFile(char *outputFileName);

/* Reads Data File's name from argv */
char* readDataFileName(char **argv);

/* Reads Output File's name from argv */
char* readOutputFileName(char **argv);

/* Reads the key from stdin */
char** readKey(FILE *stdin, int *keyCount);

/* Frees keys' memory */
void freeKey(char **key, int keyCount);

#endif
