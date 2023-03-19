#include <stdio.h>
#include <stdlib.h>
#define big(a, b) ((a) > (b) ? (a) : (b))
#define maxn 2005

int len[maxn]; //len[i] : 第i組有幾個人 
int max[maxn]; //max[i] : 第i組的最大值
int sel[maxn]; //sel[i] : 第i組有沒有被排過
int *a[maxn];  //a[i][j] : 第i組的第j人
long long sum[maxn]; //sum[i] : 第i組的總和
int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &len[i]);
            sum[i] = max[i] = sel[i] = 0;
            // 用動態記憶體
            a[i] = (int*)malloc(len[i] * sizeof(int));
            for(int j = 0 ; j < len[i] ; j++){
                scanf("%d", &a[i][j]);
                sum[i] += a[i][j];
                max[i] = big(max[i], a[i][j]);
            }
        }
        // 操作n次，每次操作找出最大的，然後把那個記為已取過，下次操作就少一次
        for(int i = 0 ; i < n ; i++){
            int step = -1;
            for(int j = 0 ; j < n ; j++){
                // 用過的跳過
                if(sel[j] == 1) continue;
                if(step == -1) step = j;
                else if(sum[j] > sum[step]) step = j;
                else if(sum[j] == sum[step] && max[j] > max[step]) step = j;
                else if(sum[j] == sum[step] && max[j] == max[step] && len[j] > len[step]) step = j;
            }
            sel[step] = 1;
            printf("%d", a[step][0]);
            for(int j = 1 ; j < len[step] ; j++) printf(" %d", a[step][j]);
            printf("\n");
        }
        for(int i = 0 ; i < n ; i++) free(a[i]);
    }
}