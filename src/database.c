#include "database.h"

void working_with_db(int args_count, char* path) {
    int check = check_db_path(args_count, path);
    char db_path[MAX_STR_LEN] = {0};
    if (check == 0) {
        strcat(db_path, init_db(BASIC_PATH));
    } else if (check == 2) {
        strcat(db_path, init_db(path));
    } else if (check == 3) {
        strcat(db_path, path);
    } else {
        strcat(db_path, BASIC_PATH);
    }
    int menu = menu_input();
    while (menu != 0) {
        if (menu == 1) {
            add_to_db(db_path);
        } else if (menu == 2) {
            show_db(db_path);
        } else if (menu == 3) {
            char date[MAX_LINE_LEN];
            scanf("%1023s", date);
            find_item_in_db(date, db_path);
        } else if (menu == 4) {
            find_max_sales(db_path);
        }
        menu = menu_input();
    }
}

char* init_db(char* db_path) {
    FILE* f;
    f = fopen(db_path, "w");
    fclose(f);
    return db_path;
}

void show_db(char* database_file) {
    FILE* f = fopen(database_file, "r");
    char line[MAX_LINE_LEN];
    int ch_counter = 0;
    while ((line[ch_counter] = fgetc(f)) != EOF) {
        if (line[ch_counter] == '\n') {
            line[ch_counter] = '\0';
            print_line(line);
            ch_counter = 0;
        } else {
            ch_counter++;
        }
    }
    fclose(f);
}

void add_to_db(char* database_file) {
    FILE* f = fopen(database_file, "a");
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char datetime[MAX_STR_LEN];
    strftime(datetime, MAX_STR_LEN, "%d.%m.%Y %H:%M:%S", tm);
    char new_line[MAX_STR_LEN];
    input_line(new_line);
    char line_to_write[MAX_STR_LEN * 2] = {0};
    strcat(line_to_write, datetime);
    strcat(line_to_write, " ");
    strcat(line_to_write, new_line);
    fputs(line_to_write, f);
    fputs("\n", f);
    fclose(f);
}

void find_item_in_db(char* date, char* db_path) {
    Field item;
    FILE* f = fopen(db_path, "r");
    char line[MAX_LINE_LEN];
    int counter = 0;
    while (fgets(line, MAX_LINE_LEN - 1, f) != NULL) {
        sscanf(line, "%10s %8s %1023s %d", item.date, item.time, item.name, &item.price);
        if (strcmp(item.date, date) == 0) {
            counter++;
            printf("%s %s %s %d\n", item.date, item.time, item.name, item.price);
        }
    }
    if (counter == 0) {
        printf("NO DATA");
    }
    fclose(f);
}

void find_max_sales(char* db_path) {
    FILE* f = fopen(db_path, "r");
    char line[MAX_LINE_LEN];
    int file_size = 0;
    while (fgets(line, MAX_LINE_LEN - 1, f) != NULL) {
        file_size++;
    }
    Field* file_arr = calloc(file_size * sizeof(Field), sizeof(Field));
    Field item;
    fclose(f);
    f = fopen(db_path, "r");
    for (int i = 0; i < file_size; i++) {
        if (fgets(line, MAX_LINE_LEN - 1, f) != NULL) {
            sscanf(line, "%10s %8s %1023s %d", item.date, item.time, item.name, &item.price);
            correct_line(item.name);
            file_arr[i] = item;
        }
    }
    fclose(f);
    sort(file_arr, file_size);
    int arr_size = uniq_count(file_arr, file_size);
    Field* sum_arr = calloc(arr_size * sizeof(Field), sizeof(Field));
    int counter = 0;
    for (int i = 0; i < file_size; i++) {
        if (strcmp(file_arr[i].name, file_arr[i + 1].name) != 0) {
            sum_arr[counter] = file_arr[i];
            sum_arr[counter].price = 0;
            counter++;
            if (i == file_size - 2) {
                sum_arr[counter + 1] = file_arr[i + 1];
                sum_arr[counter + 1].price = 0;
            }
        }
    }

    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < file_size; j++) {
            if (strcmp(file_arr[j].name, sum_arr[i].name) == 0) {
                sum_arr[i].price += file_arr[j].price;
            }
        }
    }

    Field max = sum_arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (sum_arr[i].price > max.price) {
            max = sum_arr[i];
        }
    }
    if (max.price == 0) {
        printf("NO DATA");
    } else {
        printf("%s %d", max.name, max.price);
    }
    free(file_arr);
    free(sum_arr);
}

void sort(Field* array, int len) {
    Field tmp;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (array[j].price > array[j + 1].price) {
                tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int uniq_count(Field* array, int len) {
    int counter = 1;
    for (int i = 0; i < len - 1; i++) {
        if (strcmp(array[i].name, array[i + 1].name) != 0) {
            counter++;
        }
    }
    return counter;
}