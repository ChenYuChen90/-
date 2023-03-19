#include <stdio.h>
#define maxm 505

int main(void)
{
    int n, i, j, m, arr[maxm][maxm];
        
    scanf("%d", &n);
    m = 2 * n;

    for( i = 1 ; i <= m ; i++)
    {
        for( j = 1 ; j <= m ; j++)
        {
            arr[i][j] = 0; 
        }
    }

    arr[1][1] = 1;

    for( i = 1 ; i <= m ; i++)
    {
        for( j = 1 ; j <= m ; j++)
        {
            arr[i][j] = arr[i][j-1] + 1; 
        }
        arr[i+1][j-m-1] = arr[i][j-1]; //一排一排往下填
    }
    
    for( i = 1 ; i <= m ; i++)
    {
        for( j = 1 ; j <= m ; j++)
        {   
            if( j == m)
            {
                printf("%d\n", arr[i][j]);
            }
            else
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
    
    return 0;
}