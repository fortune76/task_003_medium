#ifndef IO_UTILS_H
#define IO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"
#define MAX_STR_LEN 1024

int menu_input();
int check_db_path(int argc_count, char *arg);
void print_line(char *line);
void input_line(char *new_line);
void correct_line(char *line);
void exception();

#endif