#ifndef _FILES_H
#define _FILES_H

FILE* createFile(char* file);
void readFile(char* file);
FILE* writeFile(char* file);
// this needs to take another argument... maybe the hashmap? 
void delFile(char* file);
void closeFile(FILE* fptr);

#endif
