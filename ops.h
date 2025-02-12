#ifndef _OPS_H
#define _OPS_H

#include "decls.h"


#define VECTOR 1
#define TENSOR2D 2
#define TENSOR3D 3
#define TENSOR4D 4

Vector* vecMultiply(Scalar* scalar, Vector* vec);
Tensor2d* tensorMultiply(Scalar* scalar, Tensor2d* tensor);
Tensor3d* tensor3dMultiply(Scalar* scalar, Tensor3d* tensor);
Tensor4d* tensor4dMultiply(Scalar* scalar, Tensor4d* tensor);

Vector* vecAdd(Vector* vec, Vector* vec2);
Tensor2d* tensorAdd(Tensor2d* tensor, Tensor2d* tensor2);
Tensor3d* tensor3dAdd(Tensor3d* tensor, Tensor3d* tensor2);
Tensor4d* tensor4dAdd(Tensor4d* tensor, Tensor4d* tensor2);

Vector* vecSub(Vector* vec, Vector* vec2);
Tensor2d* tensorSub(Tensor2d* tensor, Tensor2d* tensor2);
Tensor3d* tensor3dSub(Tensor3d* tensor, Tensor3d* tensor2);
Tensor4d* tensor4dSub(Tensor4d* tensor, Tensor4d* tensor2);

void* map(int type, void (*f)(int*), void* data);
#endif