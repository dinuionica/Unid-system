// Copyright 2021 Dinu Ion Irinel
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "functions.h"
#include "menu.h"
#include "quiz_game.h"


#define LENGTH 30

#define PASSWORD_LENGTH 8

#define TRUE 1

#define LINE_LEN 300

#define SIZE 100

// function to authentificate an account
void auth_function(account_t* account) {
  printf("Hello, do you have an account? yes/no -> ");

  char* option = (char*)malloc(SIZE * sizeof(char));
  if (option == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }
  scanf("%s", option);

  if (strcmp(option, "yes") == 0) {
    login_function(account);

  } else if (strcmp(option, "no") == 0) {
    singup_function(account);
  }

  free(option);
}

// add a new account into database
void singup_function(account_t* account) {
  FILE* file_in;
  int user_exist = 0;

  printf("Enter an username for account: ");

  account->username = (char*)malloc(SIZE * sizeof(char));
  if (account->username == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  scanf("%s", account->username);

  char* line = (char*)malloc(sizeof(char) * SIZE);
  if (line == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  file_in = fopen("./headers/database.txt", "r");
  if (file_in == NULL) {
    fprintf(stderr, "Error of opening file!\n");
    return;
  }

  //check if the user exist already in ty

  while (fgets(line, sizeof(line), file_in)) {
    char *username = (char *) malloc(LENGTH * sizeof(char));

    if (username == NULL) {
      fprintf(stderr,"Error of malloc!\n");
      return;
    }

    username = strtok(line," ");
    if (strcmp(username, account->username) == 0) {
      user_exist = 1;
      break;
    }
  }

  // if the user exist in system
  if (user_exist == 1) {
    printf("This account already exist in system!\n");
    sleep(3);
    singup_function(account);

    // if the user don't exist in system
  } else {
    account->password = malloc(sizeof(account_t));
    if (account->password == NULL) {
      fprintf(stderr, "Error of malloc!\n");
      return;
    }

    // get a password without display
    account->password = getpass("Enter the password of account: ");

    FILE* file_out;
    file_out = fopen("./headers/database.txt", "at");
    if (file_out == NULL) {
      fprintf(stderr, "Error of opening file!\n");
      return;
    }

    encode_data(account->password);
    fprintf(file_out, "%s ", account->username);
    fprintf(file_out, "%s ", account->password);

    // create path
    account->path = (char*)malloc(SIZE * sizeof(char));
    if (account->path == NULL) {
      fprintf(stderr, "Error of malloc!\n");
      return;
    }
    strcpy(account->path, "./");
    strcat(account->path, account->username);
    fprintf(file_out, "%s\n", account->path);

    fclose(file_out);
    create_path(account);

    printf("Your account was added with succes!\n");
    sleep(5);
    login_function(account);
  }

  free(line);
  fclose(file_in);
}

// function to create path directories of account
void create_path(account_t* account) {
  account->path = (char*)malloc(SIZE * sizeof(char));
  if (account->path == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  strcpy(account->path, "./");
  strcat(account->path, account->username);
  mkdir(account->path, 0777);

  // make home directory
  strcat(account->path, "/home");
  mkdir(account->path, 0777);

  // make documents directory
  strcpy(account->path, "./");
  strcat(account->path, account->username);
  strcat(account->path, "/documents");
  mkdir(account->path, 0777);

  // make music directory
  strcpy(account->path, "./");
  strcat(account->path, account->username);
  strcat(account->path, "/music");
  mkdir(account->path, 0777);

  // make pictures directory
  strcpy(account->path, "./");
  strcat(account->path, account->username);
  strcat(account->path, "/music");
  mkdir(account->path, 0777);
}

// function to login
void login_function(account_t* account) {
  FILE* file = fopen("./headers/database.txt", "rt");
  if (file == NULL) {
    fprintf(stderr, "Error of opening file!\n");
    return;
  }
  printf("Enter the username of account: ");
  char* username = (char*)malloc(sizeof(char) * SIZE);
  if (username == NULL) {
    fprintf(stderr, "Error of opening file!\n");
    return;
  }

  scanf("%s", username);

  char* password = (char*)malloc(sizeof(char) * SIZE);
  if (username == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }
  // get a password without display
  password = getpass("Enter the password of account: ");

  account->username = (char*)malloc(SIZE * sizeof(char));
  if (account->username == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  account->password = (char*)malloc(SIZE * sizeof(char));
  if (account->username == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  account->path = (char*)malloc(SIZE * sizeof(char));
  if (account->path == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  // check if the user and password are correct
  int correct_information = 0;
  while (!feof(file)) {
    fscanf(file, "%s", account->username);
    fscanf(file, "%s", account->password);
    decode_data(account->password);
    fscanf(file, "%s", account->path);

    if (strcmp(username, account->username) == 0 &&
        strcmp(password, account->password) == 0) {
      chdir(account->path);
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

// function to make a file
void make_file(char* filename) {
  FILE* file_out = fopen(filename, "w");

  if (file_out == NULL) {
    fprintf(stderr, "Error of opening file!\n");
    return;
  }
  fclose(file_out);
  printf("%s was created with succes!\n", filename);
}

// function to make a directory
void make_directory(char* filename) {
  mkdir(filename, 0777);
  printf("%s was created with succes!\n", filename);
}

// function to delete a file
void remove_file(char* filename) {
  if (remove(filename) == 0) {
    printf("%s was deleted with succes!\n", filename);
  } else {
    printf("Unable to delete the file!\n");
  }
}

// function to delete a directory
void remove_directory(char* filename) {
  if (rmdir(filename) == 0) {
    printf("%s was deleted with succes!\n", filename);
  } else {
    fprintf(stderr, "Unable to delete the directory!\n");
  }
}

// function to displat all file and directories
void list_function(char* directory) {
  DIR* dp;
  struct dirent* dentry;

  if (!(dp = opendir(directory))) {
    fprintf(stderr, "Unable to display list of this directory!\n");
    return;
  }

  while (TRUE) {
    dentry = readdir(dp);
    if (dentry == NULL) {
      break;
    }

    printf("%s ", dentry->d_name);
  }
  printf("\n");
}

// function to change directory
void change_directory(char* filename) {
  if (chdir(filename) != 0) {
    fprintf(stderr, "Unable to change the directory!\n");
  }
}

// function to display the full currently path
void display_path() {
  char* path = (char*)malloc(SIZE * sizeof(char));
  if (path == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }
  getcwd(path, SIZE);

  printf("%s\n", path);
}

// function to display all content of a file
void display_content(char* filename) {
  FILE* file_in = fopen(filename, "r");

  if (file_in == NULL) {
    fprintf(stderr, "Error of opening file!\n");
    return;
  }

  char characher;
  characher = fgetc(file_in);

  while (characher != EOF) {
    printf("%c", characher);
    characher = fgetc(file_in);
  }
  fclose(file_in);
  printf("\n");
}

// function to free memory allocated
void free_memory(account_t* account) {
  free(account->username);
  free(account->password);
  free(account->path);
  free(account);
}

// function to encode password
void encode_data(char* string) {
  for (int i = 0; i < strlen(string); ++i) {
    string[i] += 3;
  }
}

// function to decode password
void decode_data(char* string) {
  for (int i = 0; i < strlen(string); ++i) {
    string[i] -= 3;
  }
}

// function to open vs-code
void open_code() {
  system("code .");
}

// function to list all of system's users
void display_users(account_t* account) {
  FILE* database = fopen("../headers/database.txt", "r");
  if (database == NULL) {
    fprintf(stderr, "Error of opening file!\n");
    return;
  }
  account->username = (char*)malloc(SIZE * sizeof(char));
  if (account->username == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  account->password = (char*)malloc(SIZE * sizeof(char));
  if (account->username == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  account->path = (char*)malloc(SIZE * sizeof(char));
  if (account->path == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  while (!feof(database)) {
    fscanf(database, "%s", account->username);
    fscanf(database, "%s", account->password);
    fscanf(database, "%s", account->path);

    printf("Username:%s -- Password:********** -- PATH:%s\n", account->username,
           account->path);
  }

  fclose(database);
}

// count numbers of lines
int count_lines(FILE* in) {
  fseek(in, 0, SEEK_SET);

  int cnt = 0;
  char line[LINE_LEN];
  while (fgets(line, LINE_LEN, in)) {
    ++cnt;
  }

  return cnt;
}

//head function to print first number_lines of a file
void head_print(char* filename, int number_lines) {
  FILE* in = fopen(filename, "r");
  int lines = count_lines(in);

  char line[LINE_LEN];

  fseek(in, 0, SEEK_SET);

  for (int i = 0; i < number_lines; ++i) {
    if (fgets(line, LINE_LEN, in) == NULL) {
      return;
    }

    printf("%s", line);
  }
}

//tail function to print last number_lines of a file
void tail_print(char* filename, int number_lines) {
  FILE* in = fopen(filename, "r");
  int lines = count_lines(in);

  char line[LINE_LEN];

  fseek(in, 0, SEEK_SET);

  for (int i = 0; i < lines - number_lines; ++i) {
      fgets(line, LINE_LEN, in);
    }

  for (int i = 0; i < number_lines; ++i) {
    if (fgets(line, LINE_LEN, in) == NULL) {
      return;
    }

    printf("%s", line);
  }
}

//function to rename a file

void rename_file(char *oldname, char *newname) {

   
   int result = rename(oldname, newname);
	
   if(result == 0) {
      printf("File renamed successfully");
   } else {
      printf("Error: unable to rename the file");
   }
}
