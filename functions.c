#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"
#define SIZE 100

//function to authentificate an account
void auth_function(account_t *account) {

    printf("Hello, do you have an account? YES/NO\n");
    
    char *option = (char *) malloc(SIZE * sizeof(char));
    if (option == NULL) {
        fprintf (stderr, "Error of malloc!\n");
        return;
    }
    scanf("%s", option);

    if (strcmp(option,"YES") == 0)  {

        login_function(account);
    
    } else if (strcmp(option,"NO") == 0) {

        singup_function(account);

    }

    free(option);
}


//add a new account into database
void singup_function(account_t *account) {


    FILE* file_in;
	int type_exist = 0;


	printf("Enter a username for account: ");

    account -> username = (char *) malloc(SIZE * sizeof(char));
    if (account -> username == NULL) {
        fprintf (stderr, "Error of malloc!\n");
        return;
    }

    scanf("%s", account -> username);

	char *line = (char *)malloc(sizeof(char) * SIZE);
    if (line == NULL) {
        fprintf (stderr, "Error of malloc!\n");
        return;
    }

	file_in = fopen("database.txt", "r");
    if (file_in == NULL) {
        fprintf (stderr, "Error of opening file!\n");
        return;
    }

	while(fgets(line, 255, file_in))
	{
		char *ptr = strstr(line, account -> username);
		if (ptr != NULL) 
		{
			type_exist = 1;
			break;
		}
	}

    //if the user exist in system
	if (type_exist == 1)
	{   
		printf("This account already exist in system!\n");
        sleep(5);
        singup_function(account);

    //if the user don't exist in system
	} else {
	
        scanf ("%s", account -> username);
        printf("\n");
        
        printf("Please enter a password for account: ");
        account -> password = malloc(sizeof(account_t));
        scanf ("%s", account -> password);
        
        FILE *file_out;
        file_out = fopen("database.txt", "at");
        if (file_out == NULL) {
            fprintf (stderr, "Error of opening file!\n");
            return;
        }


        fprintf(file_out, "%s ", account -> username);
        fprintf(file_out, "%s\n", account -> password);
        fclose(file_out);

        
        printf("Your account was added with succes!\n");
        sleep(5);
	}

    free(line);
    fclose(file_in);
   
}


void login_function(account_t *account) {

    
    FILE *file = fopen("database.txt", "rt");
    if (file == NULL) {
        fprintf (stderr, "Error of opening file!\n");
        return;
    }
    printf("Enter the username of account: ");
    char *username = (char *)malloc(sizeof(char) * SIZE);
    if (username == NULL) {
        fprintf (stderr, "Error of opening file!\n");
        return;
    }
    
    scanf("%s", username);

    printf("Enter the password of account: ");
    char *password = (char *)malloc(sizeof(char) * SIZE);
    if (username == NULL) {
        fprintf (stderr, "Error of malloc!\n");
        return;
    }

    scanf("%s", password);


    account -> username = malloc(sizeof(account_t));
    if (account -> username == NULL) {
        fprintf (stderr, "Error of malloc!\n");
        return;
    }

    account -> password = malloc(sizeof(account_t));
    if (account -> username == NULL) {
        fprintf (stderr, "Error of malloc!\n");
        return;
    }

    //check if the user and password are correct
    int correct_information = 0;
    while (!feof(file)) {
        fscanf(file, "%s", account -> username);
        fscanf(file, "%s", account -> password);
        if (strcmp(username, account -> username) == 0 && strcmp(password, account -> password) == 0) {
            
            commands_menu(account);
            sleep(5);
            correct_information = 1;
        } 
    }
    if (correct_information == 0) {

        printf("This account don't exist in sysyem!\n");
        login_function(account);
    
    }

    fclose(file);
    free(username);
    free(password);
    sleep(5);
}


void commands_menu(account_t *account) {

    printf("\033[0;31m"); 
    printf("%s@unid: ", account -> username);
    printf("\033[0m");
    char *command = (char *) malloc(SIZE * sizeof(char));
    if (command == NULL) {
        fprintf (stderr, "Error of malloc!\n");
        return;
    }
    scanf("%s", command);
}