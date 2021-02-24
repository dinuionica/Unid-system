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

#define SIZE 100

#define LENGTH 30

#define TRUE 1

void display_menu() {
  account_t* account = (account_t*)malloc(sizeof(account_t));
  if (account == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  auth_function(account);
}

void commands_menu(account_t* account) {
  // ignore the last newline
  char buf_newline[2];
  fgets(buf_newline, sizeof(buf_newline), stdin);

  char* command = (char*)malloc(LENGTH * sizeof(char));
  if (command == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }
  parse_command(command, account);

  free(command);
}

void parse_command(char* command, account_t* account) {
  char* argument = (char*)malloc(LENGTH * sizeof(char));
  if (argument == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  // display current path
  char* path = (char*)malloc(SIZE * sizeof(char));
  if (path == NULL) {
    fprintf(stderr, "Error of malloc!\n");
    return;
  }

  while (getcwd(path, SIZE) &&
         printf("\033[1;31m%s@unid\033[0m:\033[0;34m%s\033[0m$",
                account->username, path) &&
         fgets(command, LENGTH, stdin)) {
    // delete last character
    if (command[strlen(command) - 1] == '\n') {
      command[strlen(command) - 1] = '\0';
    }

    command = strtok(command, " ");

    if (strcmp(command, "mkf") == 0) {
      argument = strtok(NULL, " ");
      make_file(argument);

    } else if (strcmp(command, "mkd") == 0) {
      argument = strtok(NULL, " ");
      make_directory(argument);

    } else if (strcmp(command, "rmf") == 0) {
      argument = strtok(NULL, " ");
      remove_file(argument);

    } else if (strcmp(command, "rmd") == 0) {
      argument = strtok(NULL, " ");
      remove_directory(argument);

    } else if (strcmp(command, "ls") == 0) {
      argument = strtok(NULL, " ");
      list_function(argument);

    } else if (strcmp(command, "cd") == 0) {
      argument = strtok(NULL, " ");
      change_directory(argument);

    } else if (strcmp(command, "cat") == 0) {
      argument = strtok(NULL, " ");
      display_content(argument);

    } else if (strcmp(command, "pwd") == 0) {
      display_path();

    } else if (strcmp(command, "exit") == 0) {
      free_memory(account);
      exit(0);

    } else {
      printf("Invalid Command\n");
      continue;
    }
  }
  free(argument);
}
