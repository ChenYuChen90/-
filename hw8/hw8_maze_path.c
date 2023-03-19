#include <stdio.h>
int N, R, C;
int pathnum, minpath;
int used[105][105], spos[2];
char maze[105][105];
int dR[4] = {-1, 0, 1, 0}, dC[4] = {0, 1, 0, -1};

void solve(int posR, int posC, int step);

int main(void){
    scanf("%d", &N);
    while(N--){
        scanf("%d%d", &R, &C);
        for(int i = 1 ; i <= R ; i++){
            scanf("%s", maze[i] + 1);
            for(int j = 1 ; j <= C ; j++) if(maze[i][j] == 'S')
                // 找出迷宮開始的位置
                spos[0] = i, spos[1] = j;
        }
        pathnum = 0, minpath = 1e9;
        solve(spos[0], spos[1], 0);
        if(pathnum != 0) printf("%d %d\n", pathnum, minpath);
        else printf("0 -1\n");
    }
    return 0;
}

// 前兩個引數定位走到哪 最後一個紀錄走幾步
void solve (int posR, int posC, int step){
    if(maze[posR][posC] == 'F'){
        pathnum++;
        minpath = step < minpath ? step : minpath;
        return;
    }
    for(int d = 0 ; d < 4 ; d++){
        if((maze[posR + dR[d]][posC + dC[d]] == '$' || maze[posR + dR[d]][posC + dC[d]] == 'F')
            && used[posR + dR[d]][posC + dC[d]] != 1){
            
            used[posR + dR[d]][posC + dC[d]] = 1;
            
            solve(posR + dR[d], posC+dC[d], step + 1);
            
            used[posR + dR[d]][posC + dC[d]] = 0;
        }
    }

}