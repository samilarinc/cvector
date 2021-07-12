#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CVECTOR
#define CVECTOR

typedef struct{
    int capacity;
    int length;
    int* value;
}cvector;

cvector* cvector_new(int capacity);
void cvector_delete(cvector* vec);
int cvector_size(cvector* vec);
int cvector_max_size(cvector* vec);
int cvector_empty(cvector* vec);
void cvector_reserve(cvector* vec, int capacity);
void cvector_assign(cvector *vec, int amount, int data);
int cvector_at(cvector* vec, int index);
int cvector_first(cvector* vec);
int cvector_last(cvector* vec);
int* cvector_data(cvector* vec);
void cvector_pushback(cvector* vec, int data);
void cvector_popback(cvector* vec);
int cvector_erase(cvector* vec, int index);
void cvector_insert(cvector* vec, int data, int index);
void cvector_clear(cvector* vec);
void cvector_swap(cvector* vec1, cvector* vec2);
cvector* cvector_genfromarray(int* arr, int length);
cvector* cvector_insertarray(cvector* vec, int* arr, int length, int index);
void cvector_resize(cvector* vec, int length);
void cvector_print(cvector* vec);
int cvector_find(cvector* vec, int data);
#endif

