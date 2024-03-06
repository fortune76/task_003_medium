GC=gcc
FLAGS=-Wall -Werror -Wextra
BIN=../bin/

all: simple_db simple_db_find not_simple_db

simple_db: simple_db.c database.c io_utils.c
	$(GC) $(FLAGS) simple_db.c database.c io_utils.c -o $(BIN)simple_db

simple_db_find: simple_db.c database.c io_utils.c
	$(GC) $(FLAGS) simple_db.c database.c io_utils.c -o $(BIN)simple_db_find

not_simple_db: simple_db.c database.c io_utils.c
	$(GC) $(FLAGS) simple_db.c database.c io_utils.c -o $(BIN)not_simple_db

clean:
	rm -f *.o $(BIN)*

rebuild:
	clean all