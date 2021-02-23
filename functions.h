#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {

    char *username;
    char *password;
    char *path;


} account_t;

extern account_t account;

void auth_function(account_t *account);

void login_function(account_t *account);

void singup_function(account_t *account);

void commands_menu(account_t *account);

#endif