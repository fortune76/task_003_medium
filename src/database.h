#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "io_utils.h"

#define BASIC_PATH "../data/database.txt"
#define MAX_LINE_LEN 1024

typedef struct {
    char date[MAX_LINE_LEN];
    char time[MAX_LINE_LEN];
    char name[MAX_LINE_LEN];
    int price;
} Field;

void working_with_db(int args_count, char *path);
char *init_db(char *db_path);
void show_db(char *database_file);
void add_to_db(char *database_file);
void find_item_in_db(char *date, char *db_path);
void find_max_sales(char *db_path);
void sort(Field *array, int n);
int uniq_count(Field *array, int len);
#endif