/*
COMP20003 Assignment One (list.c)
Created by Yun-Chi Hsiao (student ID: 1074004) Aug 24th, 2020
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/******************************************************************************/

void createField(char *line, char *fields[]) {

	int n = 0;
	char *token = strtok(line, ",");

	while (token != NULL) {
		fields[n] = (char*)malloc(sizeof(char*)*strlen(token));
		assert(fields[n]);
		strcpy(fields[n], token);
		token = strtok(NULL, ",");
		n++;
	}

	/* Changing the last character "\n" to null */
	fields[NUMBEROFFIELD-1][strlen(fields[NUMBEROFFIELD-1])-1] = '\0';
}

struct node* createItem(char *line) {

	int i = 0;
	int quote = 0;
	int charIndex = 0;
	int field = 0;
	char *string = (char*) malloc(sizeof(char) * STRINGMAXCHAR);

	struct listNode *item = (struct listNode*) malloc(sizeof(struct listNode));
	assert(item);

	item->next = NULL;

	for (i = 0;i < strlen(line);i++){

		if (line[i] == QUOTE){
			quote++;
		}

		if (line[i] == COMMA && quote%2 == 0){
			string[charIndex] = TERMINATE;
			string = createTerm(string);

		switch(field){
			case 0:
				item->censusYear =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->censusYear);
				strcpy(item->censusYear, string);
				break;
			case 1:
				item->blockID =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->blockID);
				strcpy(item->blockID, string);
				break;
			case 2:
				item->propertyID =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->propertyID);
				strcpy(item->propertyID, string);
				break;
			case 3:
				item->basePropertyID =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->basePropertyID);
				strcpy(item->basePropertyID, string);
				break;
			case 4:
				item->clueSmallArea =
					(char*) malloc (sizeof(char) * (strlen(string) + 1));
				assert(item->clueSmallArea);
				strcpy(item->clueSmallArea,string);
				break;
			case 5:
				item->tradingName =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->tradingName);
				strcpy(item->tradingName, string);
				break;
			case 6:
				item->industryCode =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->industryCode);
				strcpy(item->industryCode, string);
				break;
			case 7:
				item->industryDescription =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->industryDescription);
				strcpy(item->industryDescription, string);
				break;
			case 8:
				item->xCoordinate =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->xCoordinate);
				strcpy(item->xCoordinate, string);
				break;
			case 9:
				item->yCoordinate =
					(char*) malloc(sizeof(char) * (strlen(string) + 1));
				assert(item->yCoordinate);
				strcpy(item->yCoordinate, string);
				break;
			}

			field++;
			charIndex = 0;
		}

		/* The situation of last field (location) */
		else if (line[i] == NEXTLINE || i == strlen(line) - 1){
			if (line[i] == NEXTLINE){
				string[charIndex] = TERMINATE;
			} else {
				string[charIndex++] = line[i];
				string[charIndex] = TERMINATE;
			}
			string = createTerm(string);
			item->location = (char*) malloc(sizeof(char) *
				(strlen(string) + 1));
			assert(item->location);
			strcpy(item->location, string);
		}
		/* Do nothing with carrage return ('\r') */
		else if (line[i] == CARRIAGERETURN){
		} else {
			string[charIndex++] = line[i];
		}
	}

	free(string);
	return item;
}

void foundPrintOut(FILE *outputFile, struct node *searchResult, char **fields) {
	fprintf(outputFile, "%s --> %s: %s || %s: %s || %s: %s || %s: %s || %s: %s"
			" || %s: %s || %s: %s || %s: %s || %s: %s || %s: %s || \n",
		searchResult->trading_name,
		fields[0], searchResult->census_year,
		fields[1], searchResult->block_id,
		fields[2],searchResult->property_id,
		fields[3], searchResult->base_property_id,
		fields[4], searchResult->clue_small_area,
		fields[6], searchResult->industry_code,
		fields[7], searchResult->industry_description,
		fields[8], searchResult->x_coordinate,
		fields[9], searchResult->y_coordinate,
		fields[10], searchResult->location);
}

void notFoundPrintOut(FILE *outputFile, char *key) {
	fprintf(outputFile, "%s --> NOTFOUND\n\n",key);
}

void freeFields(char *fields[]) {

	int i = 0;

	for (i = 0; i < NUMBEROFFIELD; i++) {
		free(fields[i]);
	}
}

void freeList(struct node *list, struct node *item) {

	item = list;

	while (item){
		list = item->next;
		free(item->trading_name);
		free(item->census_year);
		free(item->block_id);
		free(item->property_id);
		free(item->base_property_id);
		free(item->clue_small_area);
		free(item->industry_code);
		free(item->industry_description);
		free(item->x_coordinate);
		free(item->y_coordinate);
		free(item->location);
		free(item);
		item = list;
	}
}
