#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {a^=b;b^=a;a^=b;}

int min(int a, int b);
void sort(long long arr[][500], int y, int x, int len);
void array2d_sort(int row, int col, long long arr[][500]);

long long arr[500][500] = {};

int main(void){

    int row, col;
    scanf("%d%d", &row, &col);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            scanf("%lld", &arr[i][j]);

    array2d_sort(row, col, arr);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("%lld%c", arr[i][j], (j==col-1) ? '\n' : ' ');

    return 0;
}

int min(int a, int b){
    return (a <= b ? a : b);
}
void array2d_sort(int row, int col, long long arr[][500]){
    for(int y = 1 ; y < row ; y++) sort(arr, y, 0, min(row - y, col));
    sort(arr, 0, 0, min(col, row));
    for(int x = 1 ; x < col ; x++) sort(arr, 0, x, min(col - x, row));   
}
void sort(long long arr[][500], int y, int x, int len){
    for(int i = 0 ; i < len - 1 ; i++) for(int j = 0 ; j < len - 1 - i ; j++){
        if(arr[y + j][x + j] > arr[y + j + 1][x + j + 1]){
            long long temp;
            temp = arr[y + j][x + j];
            arr[y + j][x + j] = arr[y + j + 1][x + j + 1];
            arr[y + j + 1][x + j + 1] = temp;
        }
    }
}