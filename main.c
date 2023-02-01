#include <stdlib.h>

//creating a struct and typedefing it to arr_t
//we are typedefing struct ARRAY to arr_t
//typedef is used to create aliases for existing types or user defined types

typedef struct ARRAY {
    int len;
    int* arr;
}arr_t;


arr_t ints(int* arr1, int* arr2, int len1, int len2) {
    int c = 0;
    //each time we encounter two elements with the same value we increment c;
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (arr1[i]==arr2[j]) ++c;
        }
    }
    //declaring and initializing
    //arr is being allocated on the heap
    arr_t ret_arr = {c, malloc(c*sizeof(int))};
    int i1 = 0;
    //each time two elements are the same we assign the value to the array inside ret_arr and increment i1
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (arr1[i]==arr2[j]) {
                ret_arr.arr[i1] = arr1[i];
                ++i1;
            }
        }
    }
    return ret_arr;
}
