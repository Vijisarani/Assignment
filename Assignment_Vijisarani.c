/*
Name : Vijisarani C
Assignment Name: Implement rcat (reverse of Linux cat command) function in C programming
Date of submission: 18-06-2024
*/


//including all the libraries needed
#include <stdio.h>
#include <stdlib.h>

//function prototype
void rcat(const char *);

//using command line 
//argc -> argument count, argv -> argument vector
int main(int argc, char *argv[]) {
    //check the argument count
    if (argc != 2) {
        fprintf(stderr, "%s filename\n", argv[0]);
        return EXIT_FAILURE;
    }
    //function call
    rcat(argv[1]);

    return EXIT_SUCCESS;
}

//function declaration
void rcat(const char *filename) {
    //create a file pointer, open the file in read mode
    FILE *file = fopen(filename, "r");   
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Move file pointer to the end
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    
    // Read file content backwards
    for (long i = fileSize - 1; i >= 0; i--) {
        fseek(file, i, SEEK_SET);
        char ch = fgetc(file);
        putchar(ch);
    }
    //closing the file
    fclose(file);    
}


