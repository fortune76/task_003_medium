#include "io_utils.h"

int menu_input() {
    char menu_option[MAX_STR_LEN] = {0};
    scanf("%1023s", menu_option);
    int result = 0;
    if (strcmp(menu_option, "ADD") != 0 && strcmp(menu_option, "SHOW") != 0 &&
        strcmp(menu_option, "EXIT") != 0 && strcmp(menu_option, "FIND") != 0 &&
        strcmp(menu_option, "MAX") != 0) {
        exception();
    } else if (strcmp(menu_option, "ADD") == 0) {
        result = 1;
    } else if (strcmp(menu_option, "SHOW") == 0) {
        result = 2;
    } else if (strcmp(menu_option, "FIND") == 0) {
        result = 3;
    } else if (strcmp(menu_option, "MAX") == 0) {
        result = 4;
    } else if (strcmp(menu_option, "EXIT") == 0) {
        ;
    }
    return result;
}

int check_db_path(int argc_count, char *arg) {
    FILE *f;
    if (argc_count < 2) {
        f = fopen(BASIC_PATH, "r");
    } else {
        f = fopen(arg, "r");
    }
    int result = 0;
    if (f != NULL && argc_count < 2) {
        result = 1;
    } else if (f == NULL && argc_count == 2) {
        result = 2;
    } else if (f != NULL && argc_count == 2) {
        result = 3;
    }
    if (result == 1 || result == 3) {
        fclose(f);
    }
    return result;
}

void input_line(char *new_line) {
    scanf("%1023s", new_line);
    char tmp[MAX_LINE_LEN];
    scanf("%1023s", tmp);
    strcat(new_line, " ");
    strcat(new_line, tmp);
}

void correct_line(char *line) {
    /* шаблонизация названий товаров к CapitalCase */
    for (size_t i = 0; i < strlen(line); i++) {
        if (i == 0 && line[i] >= 97 && line[i] <= 122) {
            line[i] = line[i] - 32;
        } else if (i > 0 && line[i] >= 65 && line[i] <= 90) {
            line[i] = line[i] + 32;
        }
    }
}

void print_line(char *line) { printf("%s\n", line); }

void exception() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}