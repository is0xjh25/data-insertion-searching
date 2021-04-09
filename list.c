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
	int j = 0;
	int n = 0;
	int quoteItem = FALSE;
	int stringSize = 0;

	struct node* item = (struct node*)malloc(sizeof(struct node)*1);
	assert(item);

	/* Ensures each new node is pointing to null */
	item->next = NULL;

	/* Reads in the data of each field */
	for (i = 0; i < NUMBEROFFIELD; i++) {

		char* temp = (char*)calloc(1, sizeof(char)*(STRINGMAXCHAR+1));
		assert(temp);
		n = 0;
		/* Decides what is the format of string */
		if (quoteItem == FALSE) {
			while (line[j] != COMMA) {
				temp[n] = line[j];
				j++;
				n++;
			}

			/* Reading finished, decides what is the format of next string */
			if (line[j] == COMMA && line[j+1] == QUOTE) {
				quoteItem = TRUE;
				j += 2;
			} else {
				j++;
			}
		}
		else if (quoteItem == TRUE) {
			while ((line[j] != QUOTE || line[j+1] != COMMA) &&
					(line[j] != ENDPARENTHESIS || line[j+1] != QUOTE)){
				/* Double quote situation */
				if (line[j] == QUOTE && line[j+1] == QUOTE) {
					temp[n] = line[j];
					j += 2;
					n++;
				} else {
					temp[n] = line[j];
					j++;
					n++;
				}
			}

			/* Special case: The last field (location) */
			if (i == 10) {
			temp[n] = line[j];
			}

			/* Reading finished, decides what is the format of next string */
			if (line[j+2] != QUOTE) {
				quoteItem = FALSE;
				j += 2;
			} else {
				quoteItem = TRUE;
				j += 3;
			}
		}

		/* Reallocates to proper size and stores in the correspondind filed */
		stringSize = strlen(temp)+1;
		temp = (char*)realloc(temp, sizeof(char)*stringSize);
		assert(temp);

		switch(i) {
			case 0:
				item->census_year =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->census_year);
				strcpy(item->census_year, temp);
				break;

			case 1: item->block_id =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->block_id);
				strcpy(item->block_id, temp);
				break;

			case 2: item->property_id =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->property_id);
				strcpy(item->property_id, temp);
				break;

			case 3: item->base_property_id =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->base_property_id);
				strcpy(item->base_property_id, temp);
				break;

			case 4: item->clue_small_area =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->clue_small_area);
				strcpy(item->clue_small_area, temp);
				break;

			case 5: item->trading_name =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->trading_name);
				strcpy(item->trading_name, temp);
				break;

			case 6: item->industry_code =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->industry_code);
				strcpy(item->industry_code, temp);
				break;

			case 7: item->industry_description =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->industry_description);
				strcpy(item->industry_description, temp);
				break;

			case 8: item->x_coordinate =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->x_coordinate);
				strcpy(item->x_coordinate, temp);
				break;

			case 9: item->y_coordinate =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->y_coordinate);
				strcpy(item->y_coordinate, temp);
				break;

			case 10: item->location =
				(char*)malloc(sizeof(char)*stringSize);
				assert(item->location);
				strcpy(item->location, temp);
				break;

			default: printf("DATA FORMAT ERROR!");
				exit(1);
				break;
		}
		free(temp);
	}
	return item;
}

struct node* creatList(struct node *list, struct node *item){
	item->next = list;
	list = item;
	return list;
}

struct node* search(struct node *list, char *key) {

	if (list == NULL){
        return NULL;
	}
    if (strcmp(list->trading_name, key) == 0) {
		return list;
	}

    return search(list->next, key);
}

void searchAll(FILE *outputFile, struct node *list, char **key,
		int keyCount, char **fields){

	int i = 0;
	struct node* searchResult = NULL;

	while (i < keyCount) {
		searchResult = search(list, key[i]);

		if (searchResult == NULL) {
			notFoundPrintOut(outputFile, key[i]);

		}else{
			foundPrintOut(outputFile, searchResult, fields);
			searchResult = searchResult->next;

			while (searchResult != NULL) {
				searchResult = search(searchResult, key[i]);

				if (searchResult == NULL){
					break;

				}else{
					foundPrintOut(outputFile, searchResult, fields);
					searchResult = searchResult->next;
				}
			}
		}
		i++;
	}
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
