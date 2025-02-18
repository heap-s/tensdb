#ifndef _MAP_H
#define _MAP_H

typedef struct Node {
    char* key;
    void* value;
    struct Node* next;
} Node;

typedef struct HashMap {
    int size;
    Node** array;
} HashMap;

HashMap* initHashMap(int size);
void put(HashMap* map, char* key, void* value);
void* get(HashMap* map, char* key);
void freeMap(HashMap* map);
char* serialize(HashMap* map);

#endif