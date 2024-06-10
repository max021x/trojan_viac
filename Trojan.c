#include <stdio.h>
#include <stdlib.h>
#include "makeUsername.h"
#include "sizeFixer.h"


void main() {

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


    // // Make a file with the username name and listen to it
     FILE *user_specific_file = fopen(filename, "w");


}