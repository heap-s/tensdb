#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "decls.h"

// moving this helper function to tensor operations for each of the tensors might be nice :D
void printTensor2d(Tensor2d* tensor, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", tensor->arr[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    HashMap* map = initHashMap(10);
    if (!map) {
        printf("Failed to initialize HashMap\n");
        return 1;
    }

    int rows = 2;
    int cols = 3;
    Tensor2d* tensor = createTensor(rows, cols);
    if (!tensor) {
        printf("Failed to create Tensor2d\n");
        freeMap(map);
        return 1;
    }

    for (int i = 0; i < rows * cols; i++) {
        tensor->arr[i] = i + 1;
    }

    put(map, "myTensor", tensor);

    Tensor2d* retrievedTensor = (Tensor2d*)get(map, "myTensor");
    if (retrievedTensor) {
        printf("Retrieved Tensor2d successfully:\n");
        printTensor2d(retrievedTensor, rows, cols);
    } else {
        printf("Failed to retrieve Tensor2d\n");
    }

    freeTensor(tensor);

    freeMap(map);

    return 0;
}