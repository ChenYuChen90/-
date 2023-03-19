#include <stdio.h>
#define maxn 100
int N;
void permutation(int *arr, int start); // 一個陣列 arr 並固定第 start 格之後做操作

int main(void){
    int arr[maxn];
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++) arr[i] = i;
    permutation(arr, 1);
    return 0;
}

void permutation(int *arr, int start){
    printf("permutation: %d\n", start);
    // 結束遞迴
    if(start > N) {printf("because %d > %d, return\n", start, N); return ;}

    // 操作進行到最後一格時輸出
    if(start == N){
        printf("because start: %d = N: %d \nso the ans is : ", start, N);
        for(int i = 1 ; i <= N ; i++){
            i == N ? printf("%d \n", arr[i]) : printf("%d ", arr[i]);
        }
    }
    for(int i = start ; i <= N ; i++){
        int tmp[maxn];
        for(int j = i ; j <= N ; j++) tmp[j] = arr[j];
        
        // 交換固定位置的數字
        arr[start] = tmp[i];
        printf("After arr[%d] = tmp[%d]\n", start, i);
        for(int i = 1 ; i <= N ; i++){
            i == N ? printf("%d \n", arr[i]) : printf("%d ", arr[i]);
        }
        
        // 數字往後移一格 
        for(int j = 1 ; j <= i - start ; j++){
            arr[start + j] = tmp[start + j - 1]; // arr[i] = tmp[i - 1] = arr[i - 1]
            printf("After arr[%d + %d] = tmp[%d + %d - 1]\n", start, j, start, j);
        }
        printf("After arr[start + j] = tmp[start + j - 1]\n");
        for(int i = 1 ; i <= N ; i++){
            i == N ? printf("%d \n", arr[i]) : printf("%d ", arr[i]);
        }
        
        // 從 start + 1 項往後操作
        permutation(arr, start + 1);
        
        // 重製陣列
        for(int j = i ; j <= N ; j++) arr[j] = tmp[j];
        printf("After permutation: %d\n", start);
        for(int i = 1 ; i <= N ; i++){
            i == N ? printf("%d \n", arr[i]) : printf("%d ", arr[i]);
        }
    }
}