#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvector.h"

cvector* cvector_new(int capacity)
{
    if(capacity == 0)
        return NULL;
    cvector* vec = (cvector *)malloc(sizeof(cvector));
    if(!vec){
        printf("Allocation Error...\n");
        return NULL;
    }
    vec->value = (int *)malloc(sizeof(int) * capacity);
    if(!vec->value){
        printf("Allocation Error...\n");
        return NULL;
    }
    vec->capacity = capacity;
    vec->length = 0;
    return(vec);
}

void cvector_delete(cvector* vec)
{
    free(vec->value);
    free(vec);
}

int cvector_size(cvector* vec)
{
    return(vec->length);
}

int cvector_capacity(cvector* vec)
{
    return(vec->capacity);
}

int cvector_empty(cvector* vec)
{
    return(vec->length == 0);
}

void cvector_reserve(cvector* vec, int capacity)
{
    if(capacity >= vec->capacity){
        vec->value = (int *)realloc(vec->value, capacity*sizeof(int));
        if(!vec->value){
            printf("Allocation Error...\n");
    }
    }
    else{
        printf("Current size is bigger than desired!\n");
    }
}

void cvector_assign(cvector* vec, int amount, int data)
{
    int i;
    if(amount+1 > vec->capacity){
        vec->value = (int *)realloc(vec->value, (amount+1)*sizeof(int));
        if(!vec->value){
            printf("Allocation Error...\n");
            return;
        }
    }
    vec->capacity = amount+1;
    vec->length = amount;
    for(i = 0; i<amount; i++){
        (vec->value)[i] = data;
    }
}

int cvector_at(cvector* vec, int index)
{
    index = index<0 ?vec->length+index :index;
    if(index < vec->length && index >= 0)
        return(vec->value[index]);
    return -1;
}

int cvector_first(cvector* vec)
{
    return(vec->value[0]);
}

int cvector_last(cvector* vec)
{
    return(vec->value[(vec->length)-1]);
}

int* cvector_data(cvector* vec)
{
    return(vec->value);
}

void cvector_pushback(cvector* vec, int data)
{
    if((vec->length)+1 >= vec->capacity)
    {
        vec->value = (int *)realloc(vec->value, 2*(vec->length)*sizeof(int));
        if(!vec->value)
            printf("Allocation Error...\n");
        else
            vec->capacity = 2 * vec->length;
        return;
    }
    vec->value[vec->length] = data;
    vec->length += 1;
}

void cvector_popback(cvector* vec)
{
    if(vec->length > 0){
        vec->length -= 1;
        if(vec->length < (vec->capacity)/2){
            vec->capacity /= 2;
            vec->value = (int *)realloc(vec->value, vec->capacity*sizeof(int));
            if(!vec->value){
                printf("Allocation Error...\n");
                return;
            }
        }
    }
    else{
        printf("No elements in vector!");
    }
}

int cvector_erase(cvector* vec, int index)
{
    int i;
    int val = vec->value[index];
    for(i = index; i<vec->length-1; i++)
        vec->value[i] = vec->value[i+1];
    vec->length -= 1;
    return val;
}

void cvector_insert(cvector* vec, int data, int index)
{
    int i, temp[2];
    if((vec->length)+1 >= vec->capacity)
    {
        vec->value = (int *)realloc(vec->value, 2*vec->capacity*sizeof(int));
        if(!vec->value){
            printf("Allocation Error...\n");
            return;
        }
        vec->capacity *= 2;
    }
    temp[index%2] = data;
    for(i = index; i<(vec->length)+1; i++){
        temp[(i+1)%2] = vec->value[i];
        vec->value[i] = temp[i%2];
    }
}

void cvector_clear(cvector* vec)
{
    vec->length = 0;
    vec->capacity = 1;
    vec->value = (int *)realloc(vec->value, vec->capacity*sizeof(int));
    if(!vec->value){
        printf("Allocation Error...\n");
    }
}

void cvector_swap(cvector* vec1, cvector* vec2)///HATA!!!
{
    cvector temp;
    temp.capacity = vec1->capacity;
    temp.length = vec1->length;
    temp.value = vec1->value;

    vec1->capacity = vec2->capacity;
    vec1->length = vec2->length;
    vec1->value = vec2->value;

    vec2->value = temp.value;
    vec2->length = temp.length;
    vec2->value = temp.value;
}

cvector* cvector_genfromarray(int* arr, int length)
{
    int i;
    cvector* vec = cvector_new(length);
    for(i = 0; i < length; i++){
        vec->value[i] = arr[i];
    }
    vec->length = length;
    return vec;
}

cvector* cvector_insertarray(cvector* vec, int* arr, int length, int index)
{
    int i;
    cvector* temp = cvector_new(vec->length + length);
    for(int i = 0; i < index; i++){
        temp->value[i] = vec->value[i];
    }
    for(int i = 0; i < length; i++){
        temp->value[i+index] = arr[i];
    }   
    for(int i = index; i < vec->length; i++){
        temp->value[i+length] = vec->value[i];
    }
    temp->length = vec->length + length;
    return temp;
}

void cvector_resize(cvector* vec, int length)
{
    vec->value = (int *)realloc(vec->value, length*sizeof(int));
    if(!vec->value){
        printf("Allocation Error!\n");
        return;
    }
    vec->capacity = length;
    vec->length = vec->length > vec->capacity ?vec->capacity :vec->length;
}

void cvector_print(cvector* vec)
{
    int i;
    printf("{");
    for(i = 0; i < vec->length; i++){
        printf("%d, ", vec->value[i]);
    }
    if(vec->length > 0)
        printf("\b\b}\n");
    else
        printf("}\n");
}

int cvector_find(cvector* vec, int data)
{
    int i;
    for(i = 0; i < vec->length; i++){
        if(vec->value[i] == data){
            return i;
        }
    }
    return -1;
}
