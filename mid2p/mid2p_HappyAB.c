#include <stdio.h>
int T, K;
char sta[5][5], tar[5][5];
int spos[2], availible, temp;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int check(){
    for(int i = 1 ; i <= 3 ; i++) for(int j = 1 ; j <= 3 ; j++)
        if(sta[i][j] != tar[i][j]) return 0;
    return 1;
}
void turn(int y, int x, int step){
    if(check()) availible = 1;
    else if(step){
        for(int d = 0 ; d < 4 ; d++){
            if(sta[y+dy[d]][x+dx[d]]){
                temp = sta[y][x];
                sta[y][x] = sta[y+dy[d]][x+dx[d]];
                sta[y+dy[d]][x+dx[d]] = temp;
                turn(y+dy[d], x+dx[d], step - 1);
                temp = sta[y][x];
                sta[y][x] = sta[y+dy[d]][x+dx[d]];
                sta[y+dy[d]][x+dx[d]] = temp;
            }
        }
    }
}
int main(void){
    scanf("%d", &T);
    while(T--){
        availible = 0;
        for(int i = 0 ; i < 5 ; i++) for(int j = 0 ; j < 5 ; j++)
            sta[i][j] = tar[i][j] = 0;
        scanf("%d", &K);
        for(int i = 1 ; i <= 3 ; i++)
            scanf("%s", sta[i] + 1);
        for(int i = 1 ; i <= 3 ; i++)
            scanf("%s", tar[i] + 1);
        for(int i = 1 ; i <= 3 ; i++) for(int j = 1 ; j <= 3 ; j++)
            if(sta[i][j] == 'x') spos[0] = i, spos[1] = j;
        turn(spos[0], spos[1], K);
        printf("%s", availible ? "Yes\n" : "No\n");
    }
    return 0;
}
