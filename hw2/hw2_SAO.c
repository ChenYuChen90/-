#include <stdio.h>
#define maxn 505

int main(void)
{
    int n, a[maxn], b[maxn], c[maxn], q, l, r;
    int i, j, t;
    scanf("%d", &n);

    for( i = 1 ; i <= n ; i++)
    {
        a[i] = 0;
    }

    for( i = 1 ; i <= n ; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);

    for(t = 1 ; t <= q ; t++)
    {
        
        int times = 0, k = 0;
        scanf("%d %d", &l, &r);
        
        for( i = 1 ; i <= n ; i++)
        {
            b[i] = 0, c[i] = 0;
        }

        for(i = l ; i <= r ; i++)
        {
            for(j = i ; j <= r ; j++)
            {
                if(a[j] == a[i])
                {
                    b[i]++; //比較a[i]每個數出現的次數記在b[i]內
                }
            }
        }

        for(i = l ; i <= r ; i++)
        {
            if(times <= b[i])
            {
                times = b[i]; //b[i]最大者就是出現最多次的
            }
        }

        for(i = l ; i <= r ; i++)
        {
            if(b[i] == times)
            {
                c[k] = a[i]; //出現最多次的數字記在c[k]內
                k++;
            }
        }
        int ans = c[0];
        for(i = 0 ; i < k ; i++)
        {
            if(c[i] < ans)
            {
                ans = c[i]; //找出其中最小的數字 再輸出
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}