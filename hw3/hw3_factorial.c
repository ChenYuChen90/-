    #include <stdio.h>
    #define maxn 102
    int main(void)
    {
        int prime[26] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                        73, 79, 83, 89, 97 } ;
        int times[26], numbers[maxn];
        int i, j, k = 0;

        for(i = 1 ; i <= 25 ; i++)
        {
            times[i] = 0; //盡量用for歸0
        }

        int n;
        scanf("%d", &n);

        for(i = 0 ; i <= n ; i++)
        {
            numbers[i] = 0; //盡量用for歸0
        }
        for(i = 1 ; i <= n ; i++)
        {
            numbers[i] = numbers[i - 1] + 1; //從1到N存到numbers[]內
            //printf("%d ", numbers[i]);
        }
        
        for(i = 1 ; n >= prime[i] ; i++)
        {
            k++; //取prime[i - 1] = prime[k] prime[k]是小於N的最大質數
        }
        printf("%d %d\n", prime[k], k); //小於N的最大質數
        for(i = 1 ; i <= n ; i++)
        {
            for(j = 1 ; j <= k ; j++)
            {
                if(numbers[i] == 1)
                {
                    break;
                }
                if(numbers[i] % prime[j] == 0)
                {
                    for( ; numbers[i] % prime[j] == 0 ; )
                    {
                        times[j]++;
                        numbers[i] /= prime[j];
                        //printf("%d %d %d\n", i, numbers[i], times[j]);
                    }
                }
            }                   
        }
        /*
        for(j = 1 ; j <= k ; j++)
        {
            printf("times[%d] : %d ", prime[j], times[j]);
        }
        */

        unsigned long long ans = 1; // ans在N很大時數值會很大
        for(i = 1 ; i <= k ; i++)
        {
            times[i]++;
        }
        /*
        for(j = 1 ; j <= k ; j++)
        {
            printf("%d times[%d] : %d\n", j, prime[j], times[j]);
        }
        */
        //printf("%d\n", k);
        

        for(j = 1 ; j <= k ; j++)
        {
            ans *= times[j];
        }
        printf("%llu", ans);    
        return 0;
    }