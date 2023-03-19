#include <stdio.h>
int arr[1000][1000] = {};
int main(){
    int n, m, i, j;
    scanf("%d", &n);
    scanf("%d", &m);
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(i = 0 ; i < m ; i++){ // m
        for(j = 0 ; j < n ; j++){  // n
            if(j == n - 1){
                printf("%d\n", arr[j][i]);
            }
            else{
                printf("%d ", arr[j][i]);
            }
        }
    }
    return 0;
}