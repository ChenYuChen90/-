#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int N, K;

bool canwin(int n, int k, int state, char *state_mem);

int main(){
    int q; scanf("%d", &q);
    while(q--){
        scanf("%d%d", &N, &K);
        char *state_mem = calloc(1 << N, sizeof(char));
        if(canwin(N, K, 0, state_mem)) printf("True\n");
        else printf("False\n");
        free(state_mem);
    }
    return 0;
}

bool canwin(int n , int k, int state, char *state_mem){
    // 只有要一種辦法可行就代表correct
    if(state_mem[state] != 0) return state_mem[state] == 1;
    // 嘗試所有數字選法
    for(int i = 0 ; i < N ; i++){
        // 如果這個數字被選過，就不能再選
        if(state & (1 << i)) continue;
        // 如果現在這個玩家可以贏或是下個玩家贏不了 return true
        if( k-(i+1) <= 0 || !canwin(n, k-(i+1), state | (1 << i), state_mem)){
            state_mem[state] = 1;
            return true;
        }
    }
    // 找不到可行的方法 return false
    state_mem[state] = -1;
    return false;
}