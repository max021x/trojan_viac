#include <stdio.h>
#include <string.h>
#include <windows.h> 
#include <stdlib.h>

typedef int (__cdecl *function_nircmd)(char*); 


int check_first_six_words(char *line) {
    char *word_to_check = "nircmd";
    char line_copy[100]; // Make a copy to avoid modifying the original line
    strncpy(line_copy, line, sizeof(line_copy));
    line_copy[sizeof(line_copy) - 1] = '\0'; // Ensure null termination

    // Tokenize the line
    char *token = strtok(line_copy, " ");
        if (token == NULL || strcmp(token, word_to_check) != 0) {
            return 0; // The word is not "nircmd" or fewer than 6 words
        }
        token = strtok(NULL, " ");
    return 1; // The first six words are "nircmd"
}


void Nircmd(char *text){

    size_t ptr_len = strlen(text);
    char ptr[ptr_len];

    //printf("%s", text);

    for (int i=0; i < ptr_len; i++ ){
        if (i > 6){
            ptr[i - 7] = text[i];
        }
    }
    //printf("%s", ptr);

    HINSTANCE hinstLib; 
    function_nircmd nircmd; 
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE; 
 
    // Get a handle to the DLL module.
 
    hinstLib = LoadLibrary(TEXT("nircmd.dll")); 
 
    // If the handle is valid, try to get the function address.
 
    if (hinstLib != NULL) 
    { 
        nircmd = (function_nircmd) GetProcAddress(hinstLib, "DoNirCmd"); 
 
        // If the function address is valid, call the function.
 
        if (NULL != nircmd) 
        {   
            char *p ;
            fRunTimeLinkSuccess = TRUE;
            (nircmd) (ptr);
            
        }
        // Free the DLL module.
      
        fFreeResult = FreeLibrary(hinstLib); 
    }

}



void Shell(char *text){

    FILE *fp;
    FILE *result;
  
    char buffer[500];
    fp = popen(text,"r");
    result = fopen("Result.txt", "w");

    while (fgets(buffer, sizeof(buffer),fp) != NULL)
    {
                
        fprintf(result, "%s\n", buffer);

    }
    fclose(result);
    pclose(fp);

}


void Execute(char *text)
{
    if(check_first_six_words(text)){

        Nircmd(text);
    }
    else {
        Shell(text);
    }

}