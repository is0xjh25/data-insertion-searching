/*
COMP20003 Assignment One (list.h)
Created by Yun-Chi Hsiao (student ID: 1074004) Aug 24th, 2020

This is the header file for list.c.
The providing functions help the user to create an unsorted linked list
based on the datafile, to search the wanted informantion by keys (trading name),
and to print out the reuslts.
*/

#ifndef LISTH
#define LISTH
#define COMMA ','
#define QUOTE '"'
#define ENDPARENTHESIS ')'
#define TRUE 1
#define FALSE 0
#define LINEMAXCHAR 512
#define STRINGMAXCHAR 128
#define NUMBEROFFIELD 11
#include <stdio.h>

/* The structure of containing informantion in one node */
struct node {
	char *census_year;
	char *block_id;
	char *property_id;
	char *base_property_id;
	char *clue_small_area;
	char *trading_name;
	char *industry_code;
	char *industry_description;
	char *x_coordinate;
	char *y_coordinate;
	char *location;
	struct node *next;
};

/* Creates a node from a read in line */
struct node* createItem(char *line);

/* Creates a linked list from the orginal list and a new node */
struct node* creatList(struct node *list, struct node *item);

/* Searches a node by a key and returns the node */
struct node* search(struct node *list, char *key);

/* Creates a field list from the header line of the datafile */
void createField(char *line, char *fields[]);

/* Searches multiple nodes by a key and prints them out */
void searchAll(FILE *outputFile, struct node *list, char **key,
		int keyCount, char **fields);

/* Prints out founded results */
void foundPrintOut(FILE *outputFile, struct node *searchResult, char **fields);

/* Prints out "NOT FOUNDED" */
void notFoundPrintOut(FILE *outputFile, char *key);

/* Frees fileds' memory */
void freeFields(char *fields[]);

/* Frees lists' memory */
void freeList(struct node *list, struct node *item);

#endif
