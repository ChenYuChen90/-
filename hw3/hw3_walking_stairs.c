#include <stdio.h>
#define maxn 120

int main(void)
{
    unsigned long long  arr[maxn];
    int i, n;
    
    scanf("%d", &n);

    arr[0] = 1, arr[1] = 1, arr[2] = 1;
    
    for(i = 3 ; i <= n ; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 3];
    }
    printf("%llu\n", arr[n]);  //輸出記得改llu
    
    return 0;
}