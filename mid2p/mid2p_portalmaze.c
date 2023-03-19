#include <stdio.h>
int T, N, M;
char maze[305][305];
int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};
int use[305][305], spos[2], epos[2], portal[26][2];
void solve(int y, int x);

int main(void){
    scanf("%d", &T);
    while(T--){
        for(int i = 0 ; i < 305 ; i++) for(int j = 0 ; j < 305 ; j++)
            maze[i][j] = use[i][j] = 0;
        scanf("%d%d", &N, &M);
        for(int i = 1 ; i <= N ; i++) scanf("%s", maze[i] + 1);
        for(int i = 1 ; i <= N ; i++) for(int j = 1 ; j <= M ; j++){
            if(maze[i][j] == '$') spos[0] = i, spos[1] = j;
            if(maze[i][j] == '&') epos[0] = i, epos[1] = j;
            if(maze[i][j] >= 'A' && maze[i][j] <= 'Z'){
                char c = maze[i][j];
                portal[c - 'A'][0] = i;
                portal[c - 'A'][1] = j;
            }
        }
        solve(spos[0], spos[1]);
        if(use[epos[0]][epos[1]]) printf("Yes\n");
        else printf("No\n");
    }
}
void solve(int y, int x){
    use[y][x] = 1;
    if(maze[y][x] >= 'a' && maze[y][x] <= 'z')
        solve(portal[maze[y][x] - 'a'][0], portal[maze[y][x] - 'a'][1]);
    else{
        for(int d = 0 ; d < 4 ; d++){
            if(maze[y+dy[d]][x+dx[d]] && maze[y+dy[d]][x+dx[d]] != '#' && !use[y+dy[d]][x+dx[d]]){
                solve(y+dy[d], x+dx[d]);
            }
        }
    }
}