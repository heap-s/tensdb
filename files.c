#include <stdio.h>
#include <string.h>

#include "files.h"

FILE* createFile(char* file){
    FILE* fptr = fopen(file, "wb");
    if(fptr == NULL)
        perror("Error opening file");
    return fptr;
}

void readFile(char* file){
    FILE* fptr = fopen(file, "r");
    if(fptr == NULL) 
        perror("Error opening file");
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    char arr[size];
    fgets(arr, size, fptr); 
    fclose(fptr);
}

FILE* writeFile(char* file){
    FILE* fptr = fopen(file, "w");
    if (fptr == NULL)
        perror("Error opening file");
    return fptr;
}

void delFile(char* file){
    if(remove(file) == 0)
        printf("DB %s Deleted", file);  
    else {
        perror("Couldn't delete DB");
    }
}

void closeFile(FILE* fptr){
    fclose(fptr);
}
