#include <stdio.h>

int is_empty(FILE *fp) {
    if (fp == NULL) {
        return -1; // Indicate an error (file pointer is NULL)
    }

    // Save the current position of the file pointer
    long current_position = ftell(fp);

    // Move the file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // Try to read the first character
    int c = fgetc(fp);

    // Restore the file pointer to its original position
    fseek(fp, current_position, SEEK_SET);

    // Check if the first character is EOF
    if (c == EOF) {
        return 1; // Empty file
    } else {
        return 0; // Not empty file
    }
}