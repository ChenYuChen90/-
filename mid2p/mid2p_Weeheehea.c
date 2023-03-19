#include <stdio.h>
#define maxn 520

int tran(char *s, int xpos);
// [xpos][binary]
int exist[10][maxn];
int main(){
    int n;
    scanf("%d", &n);
    char s[15];
    for(int i = 0 ; i < n ; i++){
        scanf("%s", s);
        int xpos;
        for(int j = 0 ; j < 10 ; j++){
            if(s[j] == 'x') xpos = j;
        }
        exist[xpos][tran(s, xpos)] = 1;
    }
    int ans = 0;
    for(int i = 0 ; i < 10 ; i++) for(int j = 0 ; j < maxn ; j++)
        ans += exist[i][j];
    printf("%d\n", ans);
    return 0;
}

int tran(char *s, int xpos){
    int ret = 0;
    for(int i = 0 ; i < 10 ; i++){
        if(i == xpos) continue;
        ret = (ret << 1) | (s[i] - '0');
    }
    return ret;
}