//  用皇后問題的方法去做，先找出可以放的格子再把格子內的數字做相加
#include <stdio.h>
int nq, k = 0, q[10] = {0}, arr[10][10];
//  q[i]是儲存第i行可行的格子, k是會用到的plus[k]
long long plus[1000] = {0}, ans = -1e18, tmp;
//  plus[]是用來儲存每個解法的答案的, ans要設為-1e18避免答案很小沒辦法比出來
void place(int row);
int valid(int row, int col);// 用來判斷arr[row][col]可不可行

int main(void){
    int i, j;
    scanf("%d", &nq);
    // 2跟3是沒有解的
    if(nq == 2 || nq == 3) {printf("no solution\n"); return 0;}
    for(i = 0 ; i < nq ; i++) for(j = 0 ; j < nq ; j++)
        scanf("%d", &arr[i][j]);
    place(0);
    for(i = 0 ; i < k ; i++) if(ans < plus[i])
        ans = plus[i];
    printf("%lld\n", ans);
    return 0;
}

void place(int row){
    // 全部完成之後把那個可行發案的答案算出來放在plus[k]然後再k++
    if(row == nq){
        long long tmp = 0;
        for(int i = 0 ; i < nq ; i++)
            tmp += arr[i][q[i]];
        plus[k] = tmp;
        k++;
    }
    else{
        for(int j = 0 ; j < nq ; j++){
            if(valid(row, j) == 1){
                // 第j格可以存在q[row]
                q[row] = j;
                // 往下一行操作
                place(row + 1);
            }
        }
    }
}

int valid(int row, int col){
    for(int i = 0 ; i < row ; i++){ // i < row
        if(q[i] == col || q[i] == col - row + i || q[i] == col + row - i){
            return 0;
        }
    }
    return 1;
}