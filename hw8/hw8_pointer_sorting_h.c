#include <stdlib.h>

int** s(int* a,int len){
    // 排序
    int temp;
    for(int i = 0 ; i < len - 1 ; i++){
        for(int j = 0 ; j < len - 1 - i ; j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    len = sqrt(len);
    // 開一個二維陣列存一維陣列
    int **d2arr = (int **)malloc(len * sizeof(int *));
    for(int i = 0 ; i < len ; i++)
        d2arr[i] = a + i * len;
    return d2arr;
}