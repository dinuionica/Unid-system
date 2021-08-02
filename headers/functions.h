/* Copyright 2021 Dinu Ion Irinel */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
  char* username;
  char* password;
  char* path;

} account_t;

extern account_t account;

void auth_function(account_t* account);

void login_function(account_t* account);

void singup_function(account_t* account);

void create_path(account_t* account);

void make_file(char* filename);

void make_directory(char* filename);

void remove_file(char* filename);

void remove_directory(char* filename);

void list_function(char* directory);

void change_directory(char* filename);

void display_path();

void display_content(char* filename);

void free_memory(account_t* account);

void encode_data(char *string);

void decode_data(char *string); 

void open_code();

void display_users(account_t *account);

void head_print(char* filename, int number_lines);

void tail_print(char* filename, int number_lines);

void rename_file(char *oldname, char *newname);

#endif
