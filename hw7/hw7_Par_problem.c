#include <stdio.h>
int N;
char par[105];
// 設long long 是因為值會以2的指數倍增長
long long value(int start);
int closepos(int start);

int main(void){
    scanf("%d", &N);
    scanf("%s", par + 1);
    
    // 在最外層再套一個()，比較好做遞迴
    par[0] = '(', par[N + 1] = ')';
    
    // 因此輸出時就要把值除2
    printf("%lld\n", value(0) / 2);
    return 0;
}

// 計算值
long long value(int start){
    // basis step
    if(par[start] == '(' && par[start + 1] == ')') return 1;
    
    // start 對應的 end point
    int end = closepos(start);
    long long sum = 0;

    // 計算 start + 1 到 end - 1 的值
    for(int i = start + 1 ; i < end ; i++){
        sum += value(i);
        // 跳過已經計算過的格子
        i = closepos(i);
    }
    return sum * 2;
}


// 找出 start 對應的 end point
int closepos(int start){
    int layer = 0;

    // 注意要跑到 N + 1
    for(int i = start ; i <= N + 1 ; i++){
        if(par[i] == '(') layer++;
        else if(par[i] == ')') layer--;
        if(layer == 0) return i;
    }
    return N - 1;
}