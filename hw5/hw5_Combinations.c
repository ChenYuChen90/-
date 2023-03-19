#include <stdio.h>
// 跑陣列[0][1][2][3][4]的格子
// 012, 013, 014, 023, 024, 034, 123, 124, 234 
int arr[30] = {0}, choose[30] ={0}, n, m;
void com(int step, int cho);
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n ; i++) scanf("%d", &arr[i]);
    com(0, m);
    return 0;
}

void com(int step, int cho){
    if(cho == 0) {
        for(int i = 0 ; i < n ; i++) if(choose[i] != 0)
        // 等於1代表是在最內層
            choose[i] == 1 ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
        return ;
    }
    // 要擺在輸出下面，不然有的會先被return
    if(step == n) return;
    
    for(int i = step ; i < n ; i++){
        choose[i] = cho;
        // 格數往後一位，但可以選的數字少一個
        com(i + 1, cho - 1);
        choose[i] = 0;
    }
}