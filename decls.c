#include <stdio.h>
#include <stdlib.h>

#include "decls.h"

Scalar* createScalar(int x){
    // heap is slower and might not even be required here... Consider taking
    // this out of a struct
    Scalar* scalar = malloc(sizeof(*scalar));
    if(!scalar)
        return NULL;
    (*scalar).x = x;
    return scalar;
}

Vector* createVector(int x){
    Vector* vec = malloc(sizeof(*vec));
    if(!vec)
       return NULL; 

    (*vec).arr = malloc(x * sizeof(int));
    if(!vec -> arr) {
        free(vec);
        return NULL;
    }
    return vec;
}

Tensor2d* createTensor(int x, int y){
    Tensor2d* tensor = malloc(sizeof(*tensor));
    if(!tensor)
        return NULL;
    (*tensor).arr = malloc(x * y * sizeof(int));
    if(!tensor -> arr) {
        free(tensor);
        return NULL;
    }
    return tensor;
}

Tensor3d* createTensor3d(int x, int y, int z){
    Tensor3d* tensor = malloc(sizeof(*tensor));
    if(!tensor)
        return NULL;
    (*tensor).arr = malloc(x * y * z * sizeof(int));
    if(!tensor -> arr) {
        free(tensor);
        return NULL;
    }
    return tensor;
}

Tensor4d* createTensor4d(int x, int y, int z, int n){
    Tensor4d* tensor = malloc(sizeof(*tensor));
    if(!tensor)
        return NULL;
    (*tensor).arr = malloc(x * y * z * n *  sizeof(int));
    if(!tensor -> arr) {
        free(tensor);
        return NULL;
    }
    return tensor;
}

void freeScalar(Scalar* scalar){
    free(scalar);
}

void freeVector(Vector* vec){
    if (vec) {
       free((*vec).arr);
       free(vec);
    }
}

void freeTensor(Tensor2d* tensor){
    if (tensor) {
        free((*tensor).arr);
        free(tensor);
    }
}

void freeTensor3d(Tensor3d* tensor){
    if (tensor) {
        free((*tensor).arr);
        free(tensor);
    }
}

void freeTensor4d(Tensor4d* tensor){
    if (tensor) {
        free((*tensor).arr);
        free(tensor);
    }
}

