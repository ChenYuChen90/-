#include <stdio.h> //Ok
char board[505][505];
int main(){
    int n, m; scanf("%d %d", &n, &m);
    int i;
    for(i = 1 ; i <= n ; i++)
        //不知道為啥可以這樣輸入
        scanf("%s", board[i] + 1); // %s 輸入不用加&
    int q; scanf("%d", &q);
    while(q--){
        int x; scanf("%d", &x);
        int type = 3; // 3種可能性
        for(i = 1 ; i <= n ; i++){ // 直接讓每次 board[i][] 會往下跑
            if(board[i][x] == '\\'){
                if(x == m) { type = 2; break;} // 最右邊
                if(board[i][x + 1] == '\\') x++;
                else { type = 0; break;}
            }
            else if(board[i][x] == '/'){
                if(x == 1) {type = 1; break;} // 最左邊
                if(board[i][x - 1] == '/') x--;
                else {type = 0; break;}
            }
        }
        if(type == 0) printf("Stuck QQ\n");
        else if(type == 1) printf("Left!\n");
        else if(type == 2) printf("Right!\n");
        else printf("Position: %d\n", x);
    } 
    return 0;
}
