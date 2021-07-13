#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "cvector.h"

class cvector{
    public:
    
    cvector(int cap = 1)
    {
        capacity = cap;
        value = new int[capacity];
        length = 0;
    }

    void fillWithArray(int* arr, int lengthArray)
    {
        int* temp = new int[lengthArray];
        capacity = lengthArray;
        length = lengthArray;
        for(int i = 0; i < length; i++){
            temp[i] = arr[i];
        }
        value = temp;
        delete[] temp;
    }

    ~cvector()
    {
        delete[] value;
    }
    
    int getSize()
    {
        return length;
    }

    int getCapacity()
    {
        return capacity;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void reserve(int newCapacity)
    {
        if(newCapacity >= capacity){
            int* temp = new int[newCapacity];
            for(int i = 0; i < length; i++){
                temp[i] = value[i];
            }
            capacity = newCapacity;
            value = temp;
            delete[] temp;
        }
        else{
            std::cout<<"Desired size is smaller than current size!\n";
        }
    }

    void assign(int amount, int data)
    {
        while(amount > capacity){
            capacity *= 2;
        }
        int* temp = new int[capacity];
        for(int i = 0; i < amount; i++){
            temp[i] = data;
        }
        value = temp;
        delete[] temp;
        length = amount;
    }

    int cvector::operator[](size_t index) const
    {
        if(index > length)
            return -1;
        if(index < 0)
            if(length+index > 0)
                index = length + index;
            else
                return -1;
        return value[index];
    }

    // int at(int index){
    //     return (*this)[index];
    // }

    int first()
    {
        if(length > 0)
            return value[0];
        return -1;
    }

    int last()
    {
        if(length > 0)
            return value[length-1];
        return -1;
    }

    int* getVecInArray()
    {
        return value;
    }

    void push_back(int data)
    {
        if(length+1 > capacity){
            capacity *= 2;
            int* temp = new int[capacity];
            for(int i = 0; i < length; i++){
                temp[i] = value[i];
            }
            value = temp;
            delete[] temp;
        }
        value[length] = data;
        length += 1;
    }

    void pop_back()
    {
        length -= 1;
    }

    int remove(int index)
    {
        int data = value[index];
        for(int i = index; i < length; i++){
            value[i] = value[i+1];
        }
        length -= 1;
        return data;
    }

    void shrink_to_fit()
    {
        if(length == 0){
            return;
        }
        else{
            while(length <= capacity/2){
                capacity /= 2;
            }
            int* temp = new int[capacity];
            for(int i = 0; i < length; i++){
                temp[i] = value[i];
            }
            value = temp;
            delete[] temp;
        }
    }

    void insert(int data, int index)
    {
        int temp[2];
        if(length+1 >= capacity){
            capacity *= 2;
            int* temp = new int[capacity];
            for(int i = 0; i < length; i++){
                temp[i] = value[i];
            }
            value = temp;
            delete[] temp;
        }
        temp[index%2] = data;
        for(int i = index; i < length+1; i++){
            temp[(i+1)%2] = value[i];
            value[i] = temp[i%2];
        }
    }

    void clear()
    {
        length = 0;
        capacity = 1;
        delete[] value;
        value = new int[capacity];
    }

    int find(int data, int start = 0, int occurrenceNumber = 1)
    {
        if(start > length)
            return -1;
        for(int i = start; i < length; i++){
            if(value[i] == data){
                occurrenceNumber--;
                if(occurrenceNumber == 0){
                    return i;
                }
            }
        }
    }

    void print()
    {
        printf("{");
        for(int i = 0; i < length; i++){
            printf("%d, ", value[i]);
        }
        if(length > 0)
            printf("\b\b}\n");
        else
            printf("}\n");
    }

    void resize(int newSize)
    {
        int* temp = new int[newSize];
        int small = newSize<length ?newSize :length;
        for(int i = 0; i < small; i++){
            temp[i] = value[i];
        }

        capacity = newSize;
        length = small;
    }

    void cvector_insertarray(int* arr, int lengthArray, int index)
    {
        int* temp = new int[length + lengthArray];
        for(int i = 0; i < index; i++){
            temp[i] = value[i];
        }
        for(int i = 0; i < length; i++){
            temp[i+index] = arr[i];
        }   
        for(int i = index; i < length; i++){
            temp[i+length] = value[i];
        }
        length += lengthArray;
        value = temp;
        delete[] value;
    }

    void swap(cvector& vec2)
    {
        int* temp = new int[vec2.capacity];
        int cap, size;
        std::copy(vec2.value, vec2.value+length, temp);
        cap = vec2.capacity;
        size = vec2.length;
        vec2.value = value;
        vec2.length = length;
        vec2.capacity = capacity;
        length = size;
        value = temp;
        capacity = cap;
        delete[] temp;
    }

    protected:
    int capacity;
    int length;
    int* value;
};


