#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

// this is temporary
#define MAX_SIZE 2048

HashMap* initHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    if (size > MAX_SIZE) {
        perror("Overflow");
        free(map);
        return NULL;
    }
    map->array = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        map->array[i] = NULL;
    }
    return map;
}

int hash(char* key, int size) {
    int hash_value = 0;
    while (*key) {
        hash_value = (hash_value * 31 + *key) % size;
        key++;
    }
    return hash_value;
}

void put(HashMap* map, char* key, void* value) {
    int index = hash(key, map->size);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = strdup(key);  // Use strdup to duplicate the key string
    node->value = value;
    node->next = map->array[index];
    map->array[index] = node;
}

void* get(HashMap* map, char* key) {
    int index = hash(key, map->size);
    Node* node = map->array[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    return NULL;
}

void freeMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->array[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->key);  // Free the duplicated key string
            free(temp);
        }
    }
    free(map->array);
    free(map);
}