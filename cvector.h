#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CVECTOR
#define CVECTOR

class cvector{
    cvector(int cap = 1);
    void fillWithArray(int* arr, int lengthArray);
    ~cvector();
    int getSize();
    int getCapacity();
    bool isEmpty();
    void reserve(int newCapacity);
    void assign(int amount, int data);
    int cvector::operator[](size_t index) const;
    // int at(int index);
    int first();
    int last();
    int* getVecInArray();
    void push_back(int data);
    void pop_back();
    int remove(int index);
    void shrink_to_fit();
    void insert(int data, int index);
    void clear();
    int find(int data, int start = 0, int occurrenceNumber = 1);
    void print();
    void resize(int newSize);
    void cvector_insertarray(int* arr, int lengthArray, int index);
    void swap(cvector& vec2);
};
#endif

