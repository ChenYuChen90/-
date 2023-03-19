#include <stdio.h>
#define maxn 105
#define maxm 105

int main(void)
{
    int n, m, arr[maxn][maxm];
    int i, j;

    scanf("%d %d", &n, &m);
    
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= m ; j++)
        {
            arr[i][j] = 0; 
        }
    }

    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= m ; j++)
        {
            scanf("%d", &arr[i][j]); //輸入陣列
        }
    }

    int q, u, d, l, r, w;
    scanf("%d", &q);

    for(w = 1 ; w <= q ; w++) //幫幾次
    {
        int ans = 0;
        scanf("%d %d %d %d", &u, &d, &l, &r);

        for(i = u ; i <= d ; i++)
        {
            for(j = l ; j <= r ; j++)
            {
                if(ans < arr[i][j])
                {
                    ans = arr[i][j]; //比大小
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}