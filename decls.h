#ifndef _DECLS_H
#define _DECLS_H

typedef struct Scalar{
    int x;
} Scalar;

typedef struct Vector{
    int *arr;
    int x;
} Vector;

typedef struct Tensor2d{
    int *arr;
    int x; 
    int y;
} Tensor2d;

typedef struct Tensor3d{
    int *arr;
    int x;
    int y; 
    int z;
} Tensor3d;

typedef struct Tensor4d{
    int *arr;
    int x;
    int y;
    int z;
    int n; 
} Tensor4d;

Scalar* createScalar(int x);
Vector* createVector(int x);
Tensor2d* createTensor(int x, int y);
Tensor3d* createTensor3d(int x, int y, int z);
Tensor4d* createTensor4d(int x, int y, int z, int n);

void freeScalar(Scalar* scalar);
void freeVector(Vector* vec);
void freeTensor(Tensor2d* tensor);
void freeTensor3d(Tensor3d* tensor);
void freeTensor4d(Tensor4d* tensor);

#endif
