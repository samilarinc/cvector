#include <stdio.h>
#include "cvector.h"

int main()
{
    int capacity = 1;
    cvector* vect = cvector_new(capacity);
    cvector* vect2 = cvector_new(capacity);
    int arr[7] = {0,1,2,3,4,5,6};
    int arr2[3] = {10, 20, 30};
    vect = cvector_genfromarray(arr, 7);
    vect2 = cvector_insertarray(vect, arr2, 3, 2);
    cvector_print(vect2);

    system("pause");
    return 0;
}
