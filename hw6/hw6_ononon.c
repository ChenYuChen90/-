#include <stdio.h>
int n, m, s[22][22], ans = 1e9;
int dy[]={0, -1, 0, 1, 0}, dx[]={0, 0, 1, 0, -1}; //五個要換的格子
// 每一格都有操作到
void slove(int row, int col, int times);
// 將0換1，1換0
void turn(int row, int col);
// 判斷是否全部為0
int check();

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", &s[i][j]);
    slove(1,1,0);
    if(ans != 1e9) printf("%d\n", ans);
    else printf("no solution\n");
}

void slove(int row, int col, int times){
    for(int i = 0 ; i < 2 ; i++){
        // i = 1 才會轉
        if(i) turn(row, col);
        // 每次跑到最後一格 進行一次判斷
        if(row == n && col == m){
            // 直接+i 就不用在額外設一個變數
            if(check()) if(times + i < ans) ans = times + i;
        }
        // 換行，記得用else if不然會跟上面的重疊，在row == n && col == m 也會跑這個敘述
        else if(col == m) slove(row + 1, 1, times + i);
        // 往右
        else slove(row, col + 1, times + i);
        // 把那一格轉回來，避免引響到其他操作下
        if(i) turn(row, col);
    }
    return;
}

void turn(int row, int col){
    for(int i = 0 ; i < 5 ; i++)
        s[row + dy[i]][col + dx[i]] = (s[row + dy[i]][col + dx[i]] + 1) % 2;
    return;
}

int check(){
    for(int i = 1 ; i <= n ; i++) for(int j = 1 ; j <= m ; j++) if(s[i][j] == 0) return 0;
    return 1;
}