#include <stdio.h>
#define maxm 505

int main(void)
{
    int n, m, arr[maxm][maxm], p, q;
    scanf("%d", &n);

    m = 2 * n;

    for(p = 1 ; p <= m ; p++)
    {
        for(q = 1 ; q <= m ; q++)
        {
            arr[p][q] = 0;
        }
    }
    int i = 1, j = 1, w = m;
    for( ; i <= w ; )
    {   
        for( ; j < w ; j++)
        {
            arr[i][j] = arr[i][j - 1] + 1;
        }
        arr[i][j] = arr[i][j - 1] + 1, i++;
        for( ; i < w ; i++)
        {
            arr[i][j] = arr[i - 1][j] + 1;
        }
        arr[i][j] = arr[i - 1][j] + 1, j--;
        for( ; j > m - w + 1 ; j--)
        {
            arr[i][j] = arr[i][j + 1] + 1;
        }
        arr[i][j] = arr[i][j + 1] + 1, i--;
        for( ; i > m - w + 1 ; i--)
        {
            arr[i][j] = arr[i + 1][j] + 1;
        }
        i++, j++;
        if(arr[i][j] != m * m - 1)
        {
            arr[i][j] = arr[i][j - 1] + 1;
        }
        w --;
    }

    for( i = 1 ; i <= m ; i++)
    {
        for( j = 1 ; j <= m ; j++)
        {
            if( j == m )
            printf("%d\n", arr[i][j]);
            else
            printf("%d ", arr[i][j]);
        }
    }

    return 0;
}