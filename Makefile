build:main.c menu.c menu.h functions.c functions.h
	gcc main.c menu.c menu.h functions.c functions.h -o main && ./main

clear:
	rm main