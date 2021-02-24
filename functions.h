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

#endif