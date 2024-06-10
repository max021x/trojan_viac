#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <lmcons.h>
#include <string.h>


char* makeUsername()
{

    char winUsername[UNLEN+1];
    DWORD winUsername_len = UNLEN+1;
    GetUserNameA((TCHAR*)winUsername , &winUsername_len );


    FILE *pf;

    char buffer[500];
    pf = popen("wmic os get serialnumber","r");


    if (fgets(buffer, sizeof(buffer), pf) != NULL) {
        // Read the second line (assuming the serial number is on the second line)
        if (fgets(buffer, sizeof(buffer), pf) != NULL) {
            // Extract the serial number (assuming format consistency)
            char *serial_number = strtok(buffer, "\n");

            // Combine username and serial number with a space separator
            size_t combined_len = strlen(winUsername) + 3 + strlen(serial_number) + 1; // Account for space, null terminator
            char *combined_username = (char*)malloc(combined_len * sizeof(char));

            snprintf(combined_username, combined_len, "%s - %s", winUsername, serial_number);
            //printf("Combined Username: %s\n", combined_username);

            return combined_username;
        }
    }
    pclose(pf);
}