#include <stdio.h>
#include <stdlib.h>
typedef struct floor
{
    int i;
    struct floor *d[4];
}floor;
int Q, T, dir, val;
const int rdir[] = {2,3,0,1};
floor* floor_create(floor* prev, int dir, int num){
    floor* flr = (floor*)malloc(sizeof(floor));
    flr->i = num;
    flr->d[dir] = prev;
    return flr;
}
int main(){
    floor *curr, *portal;
    portal = curr = floor_create(NULL, 0, 0);
    for(scanf("%d", &Q); Q--; ){
        scanf("%d", &T);
        switch(T){
            case 1 :
                scanf("%d%d", &dir, &val);
                curr->d[dir] = floor_create(curr, rdir[dir], val);
                break;
            case 2 :
                scanf("%d", &dir);
                curr = curr->d[dir];
                break;
            case 3 :
                scanf("%d", &val);
                curr-> i = val;
                break;
            case 4 :
                printf("%d\n", curr->i);
                break;
            case 5 :
                portal = curr;
                break;
            case 6 :
                curr = portal;
                break;
        }
    }
    return 0;
}