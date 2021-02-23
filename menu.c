//function to display menu 

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void display_menu() {

    account_t *account = (account_t *) malloc(sizeof(account_t));
    if (account == NULL) {
        fprintf(stderr,"Error of malloc!\n");
        return;
    }

    auth_function(account);
}
