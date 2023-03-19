#include <stdio.h> //Ok
// 鏡像時最底下那行會跑掉 : 陣列不能直接開[n][m] 會被限制
// TLE 6/10 : 轉四次 = 轉一圈
#define maxn 105
int main(){
    int n, m, i, j, arr[maxn][maxn], arrstep[maxn][maxn];
    scanf("%d %d", &n, &m);
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            scanf("%d", &arr[i][j]);
            arrstep[i][j] = arr[i][j];
        }
    }
    int q; scanf("%d", &q);
    q %= 4;
    while(q--){
        int sum;
        sum = n + m, n = sum - n, m = sum - m;
        for(i = 0 ; i < n ; i++){ // 轉斜角
            for(j = 0 ; j < m ; j++){
                arrstep[i][j] = arr[j][i];
            }
        }
        for(i = 0 ; i < n ; i++){ // 左右鏡像
            for(j = 0 ; j < m ; j++){
                arr[i][j] = arrstep[i][(m - 1) - j];
            }
        }
    }    
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(j == m - 1)
                printf("%d\n", arr[i][j]);
            else
                printf("%d ", arr[i][j]);
        }
    }
    return 0;
}
