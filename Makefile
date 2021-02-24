build:main.c menu.c menu.h functions.c functions.h
	gcc main.c functions.c functions.h menu.c menu.h -o main && ./main 

clear:
	rm main