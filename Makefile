
# compiler setup
CC=gcc
# define targets
TARGETS=unid_system

build: $(TARGETS)

unid_system: unid_system.c ./headers/functions.h ./headers/functions.c ./headers/menu.h ./headers/menu.c ./headers/quiz_game.c ./headers/quiz_game.c
	$(CC) $(CFLAGS) unid_system.c  ./headers/functions.c ./headers/menu.c ./headers/quiz_game.c -o unid_system

pack:
	zip -FSr unid_system.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
