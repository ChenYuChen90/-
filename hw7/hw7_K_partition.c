#include <stdio.h>
#include <string.h>
int q, N, K, arr[12], set[12], availible;
void solve(int, int, int, int, int);

int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &N, &K);
        for(int i = 0 ; i < N ; i++) scanf("%d", &arr[i]);
        // reset the status
        for(int i = 0 ; i < N ; i++) set[i] = 0;
        availible = 0;
        solve(0, 1, 0, 0, 0);
        printf("%s\n", availible == 1 ? "True" : "False");
    }
    return 0;
}
/*
step:current step 第幾格
setidx:the index of the current set 第幾堆
picknum:count how many numbers have been chosen(used to see if you have picked)
        這堆有沒有取過數字，或是取幾個數字了
cursum:current sum of the set 目前這堆的總和
cmpsum:the sum of the first set 第一堆的總和
*/
void solve(int step, int setidx, int picknum, int cursum, int cmpsum){
    if(step == N){
        // 沒選數字 return
        if(picknum == 0) return;

        // 若是第一堆則記錄這一堆的和 並移到下一堆操作
        else if(setidx == 1) solve(0, setidx + 1, 0, 0, cursum);
        
        // 跟第一組的相加不相等
        else if(cursum != cmpsum) return;
        
        // 操作下一組
        else if(setidx < K) solve(0, setidx + 1, 0, 0, cmpsum);
        
        // 到第K堆且每個數字都有被選過就可以記錄有解
        else if(setidx == K){
            for(int i = 0 ; i < N ; i++) if(set[i] == 0) return;
            availible = 1;
        }
        return;
    }
    solve(step + 1, setidx, picknum, cursum, cmpsum);
    
    // 將 第step格 數字分在 setidx組 裡
    if(set[step] == 0){
        set[step] = setidx;
        solve(step + 1, setidx, picknum + 1, cursum + arr[step], cmpsum);
        set[step] = 0;
    }
    return;
}