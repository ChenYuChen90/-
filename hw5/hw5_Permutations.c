#include <stdio.h> // OK
#define maxn 100
int n;
void per(int *arr, int step); // 一個陣列 arr 並固定第 start 格 之後做全排列 要用*arr裁示代表那個陣列

int main(){
    scanf("%d", &n);
    int arr[maxn];
    for(int i = 1 ; i <= n ; i++) arr[i] = i;
    per(arr, 1);
    return 0;
}

void per(int *arr, int step){
    // 結束遞迴
    if(step > n) return;
    // 操作進行到最後一格時輸出
    if(step == n) for(int i = 1 ; i <= n ; i++)
        i == n ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
    
    // i 從 step 開始
    for(int i = step ; i <= n ; i++){
        int tmp[maxn];
        // 另設一個 j 讓他從 i 開始
        for(int j = i ; j <= n ; j++) tmp[j] = arr[j];
        
        // 交換固定位置的數字
        // arr[step] 跟 後面的數字換 ， i 會加加
        arr[step] = tmp[i];
        
        // 數字往後移一格
        // 從 j = 1 開始 ++ 到i - step (有幾位數要移) 
        // arr[], tmp[] 都是從step 開始加
        for(int j = 1 ; j <= i - step ; j++) arr[step + j] = tmp[step + j - 1];
        
        // 從start + 1 項往後操作
        per(arr, step + 1);
        
        // 重製陣列
        for(int j = i ; j <= n ; j++) arr[j] = tmp[j];
    }
}