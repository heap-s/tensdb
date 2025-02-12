#include <stdio.h>
#include <stdlib.h>

#include "ops.h"
#include "decls.h"

#define VECTOR 1
#define TENSOR 2
#define TENSOR3 3
#define TENSOR4 4

Vector* vecMultiply(Scalar* scalar, Vector* vec){
	Vector* newVec = createVector(vec -> x);
	if(newVec == NULL)
		return NULL;
	
	for (int i = 0; i < vec -> x; i++){
		newVec -> arr[i] = vec -> arr[i] * scalar -> x;
	}
	free(vec);
	return newVec;
}

Tensor2d* tensorMultiply(Scalar* scalar, Tensor2d* tensor){
	Tensor2d* newTensor = createTensor(tensor -> x, tensor -> y);
	if(newTensor == NULL)
		return NULL;

	for(int i = 0; i < tensor -> x * tensor -> y; i++){
		newTensor -> arr[i] = tensor -> arr[i] * scalar -> x;
	}
	free(tensor);
	return newTensor;
}

Tensor3d* tensor3dMultiply(Scalar* scalar, Tensor3d* tensor){
	Tensor3d* newTensor = createTensor3d(tensor -> x, tensor -> y, tensor -> z);
	if(newTensor == NULL)
		return NULL;
	
	for(int i = 0; i < tensor -> x * tensor -> y * tensor -> z; i++){
		newTensor -> arr[i] = tensor -> arr[i] * scalar -> x;
	}
	free(tensor);
	return newTensor;
}

Tensor4d* tensor4dMultiply(Scalar* scalar, Tensor4d* tensor){
	Tensor4d* newTensor = createTensor4d(tensor -> x, tensor -> y, tensor -> z, tensor -> n);
	if(newTensor == NULL)
		return NULL;
	
	for(int i = 0; i < tensor -> x * tensor -> y * tensor -> z * tensor -> n; i++){
		newTensor -> arr[i] = tensor -> arr[i] * scalar -> x;
	}
	free(tensor);
	return newTensor;
}

Vector* vecAdd(Vector* vec, Vector* vec2){
	Vector* vecSum = createVector(vec -> x);
	if(vecSum == NULL)
		return NULL;
	
	for(int i = 0; i < vec -> x; i++){
		vecSum -> arr[i] = vec -> arr[i] + vec2 -> arr[i];
	}
	free(vec);
	free(vec2);
	return vecSum;
}

Tensor2d* tensorAdd(Tensor2d* tensor, Tensor2d* tensor2){
	Tensor2d* tensorSum = createTensor(tensor -> x, tensor -> y);
	if(tensorSum == NULL)
		return NULL;
	
	for(int i = 0; i < tensor -> x * tensor -> y; i++){
		tensorSum -> arr[i] = tensor -> arr[i] + tensor2 -> arr[i];
	}
	free(tensor);
	free(tensor2);
	return tensorSum;
}

Tensor3d* tensor3dAdd(Tensor3d* tensor, Tensor3d* tensor2){
	Tensor3d* tensorSum = createTensor3d(tensor -> x, tensor -> y, tensor -> z);
	if(tensorSum == NULL)
		return NULL;
	
	for(int i = 0; i < tensor -> x * tensor -> y * tensor -> z; i++){
		tensorSum -> arr[i] = tensor -> arr[i] + tensor2 -> arr[i];
	}
	free(tensor);
	free(tensor2);
	return tensorSum;
}

Tensor4d* tensor4dAdd(Tensor4d* tensor, Tensor4d* tensor2){
	Tensor4d* tensorSum = createTensor4d(tensor -> x, tensor -> y, tensor -> z, tensor -> n);
	if(tensorSum == NULL)
		return NULL;
	
	for(int i = 0; i < tensor -> x * tensor -> y * tensor -> z * tensor -> n; i++){
		tensorSum -> arr[i] = tensor -> arr[i] + tensor2 -> arr[i];
	}
	free(tensor);
	free(tensor2);
	return tensorSum;
}

Vector* vecSub(Vector* vec, Vector* vec2){
	Vector* out = createVector(vec -> x);
	if(out == NULL)
		return NULL;

	for(int i = 0; i < vec -> x; i++){
		out -> arr[i] = vec -> arr[i] - vec2 -> arr[i];
	}
	free(vec);
	free(vec2);
	return out;
}

Tensor2d* tensorSub(Tensor2d* tensor, Tensor2d* tensor2) {
	Tensor2d* out = createTensor(tensor -> x, tensor -> y);
	if(out == NULL)
		return NULL;

	for(int i = 0; i < tensor -> x * tensor -> y; i++){
		out -> arr[i] = tensor -> arr[i] - tensor2 -> arr[i];
	}
	free(tensor);
	free(tensor2);

	return out;
}

Tensor3d* tensor3dSub(Tensor3d* tensor, Tensor3d* tensor2) {
	Tensor3d* out = createTensor3d(tensor -> x, tensor -> y, tensor -> z);
	if(out == NULL)
		return NULL;

	for(int i = 0; i < tensor -> x * tensor -> y * tensor -> z; i++){
		out -> arr[i] = tensor -> arr[i] - tensor2 -> arr[i];
	}
	free(tensor);
	free(tensor2);

	return out;
}

Tensor4d* tensor4dSub(Tensor4d* tensor, Tensor4d* tensor2) {
	Tensor4d* out = createTensor4d(tensor -> x, tensor -> y, tensor -> z, tensor -> n);
	if(out == NULL)
		return NULL;

	for(int i = 0; i < tensor -> x * tensor -> y * tensor -> z * tensor -> n; i++){
		out -> arr[i] = tensor -> arr[i] - tensor2 -> arr[i];
	}
	free(tensor);
	free(tensor2);

	return out;
}

// this particular function might need some work, but it's meant to give the user
// control and allow them to make real composable functions

// use the free API from decls.h to free these below?
void* map(int type, void (*f)(int*), void* data) {
    switch (type) {
        case VECTOR: {
            Vector* vector = (Vector*)data;
            Vector* result = (Vector*)malloc(sizeof(Vector));
            result->x = vector->x;
            result->arr = (int*)malloc(result->x * sizeof(int));
            for (int i = 0; i < vector->x; i++) {
                result->arr[i] = vector->arr[i];
                f(&result->arr[i]);
            }
            return result;
        }
        case TENSOR2D: {
            Tensor2d* tensor = (Tensor2d*)data;
            Tensor2d* result = (Tensor2d*)malloc(sizeof(Tensor2d));
            result->x = tensor->x;
            result->y = tensor->y;
            result->arr = (int*)malloc(result->x * result->y * sizeof(int));
            for (int i = 0; i < tensor->x * tensor->y; i++) {
                result->arr[i] = tensor->arr[i];
                f(&result->arr[i]);
            }
            return result;
        }
        case TENSOR3D: {
            Tensor3d* tensor = (Tensor3d*)data;
            Tensor3d* result = (Tensor3d*)malloc(sizeof(Tensor3d));
            result->x = tensor->x;
            result->y = tensor->y;
            result->z = tensor->z;
            result->arr = (int*)malloc(result->x * result->y * result->z * sizeof(int));
            for (int i = 0; i < tensor->x * tensor->y * tensor->z; i++) {
                result->arr[i] = tensor->arr[i];
                f(&result->arr[i]);
            }
            return result;
        }
        case TENSOR4D: {
            Tensor4d* tensor = (Tensor4d*)data;
            Tensor4d* result = (Tensor4d*)malloc(sizeof(Tensor4d));
            result->x = tensor->x;
            result->y = tensor->y;
            result->z = tensor->z;
            result->n = tensor->n;
            result->arr = (int*)malloc(result->x * result->y * result->z * result->n * sizeof(int));
            for (int i = 0; i < tensor->x * tensor->y * tensor->z * tensor->n; i++) {
                result->arr[i] = tensor->arr[i];
                f(&result->arr[i]);
            }
            return result;
        }
        default:
            return NULL;
    }
}