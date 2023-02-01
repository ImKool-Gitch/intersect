#include <stdio.h>
#include <stdlib.h>

typedef struct ARRAY {
    int len;
    int* arr;
}arr_t;


arr_t ints(int* arr1, int* arr2, int len1, int len2) {
    int c = 0;
  
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (arr1[i]==arr2[j]) ++c;
        }
    }
  
    arr_t ret_arr = {c, malloc(c*sizeof(int))};
  
    int i1 = 0;
  
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

int main(void) {
    int rr[] = {1,4,10,6,9};
    int tt[] = {9,6,3};
  
    arr_t yes = ints(rr, tt, 5, 3);
  
    for (int i = 0; i < yes.len; ++i) printf("%d\n", yes.arr[i]);
  
    free(yes.arr);
  
    return 0;
}
