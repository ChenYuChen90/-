    #include <stdio.h>
    #define maxn 102
    int main(void)
    {
        int prime[26] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                        73, 79, 83, 89, 97 } ;
        int n, number[maxn], times[26];
        int i, j, k = 0;
        for(i = 1 ; i <= 25 ; i++)
            times[i] = 0; //盡量用for歸0
        scanf("%d", &n);
        for(i = 0 ; i <= n ; i++)
            number[i] = 0; //盡量用for歸0
        for(i = 1 ; i <= n ; i++)
            number[i] = number[i - 1] + 1;
        for(i = 1 ; n >= prime[i] ; i++)
            k++;
        for(i = 1 ; i <= n ; i++)
        {
            for(j = 1 ; j <= k ; j++)
            {
                if(number[i] == 1)
                    break;
                if(number[i] % prime [j] == 0)
                {    
                    for( ; number[i] % prime[j] == 0 ; )
                        number[i] /= prime[j], times[j]++; 
                }
            }
        }
        unsigned long long ans = 1;
        for(i = 1 ; i <= k ; i++)
            times[i]++;
        for(i = 1 ; i <= k ; i++)
            ans = ans * times[i];
        printf("%llu", ans);
        return 0;
    }