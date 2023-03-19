#include <stdio.h>
int arr[22] = {};
int solve(int M){
    if(M == 0) return 1;
    if(!arr[M]){
        arr[M] += solve(M - 1) * 3;
        for(int i = 2 ; i <= M ; i++)
            arr[M] += solve(M - i) * 2;
    }
    return arr[M];
}

int main(void){
    int N; scanf("%d", &N);
    printf("%d", solve(N/2));
    return 0;
}