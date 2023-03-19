#include <stdio.h>
#define maxn 10005
int main(void){
    int number1, number2, divisor[maxn], common[maxn];
    int small_number;
    int i;
    scanf("%d %d", &number1, &number2);
    if(number1 >= number2)
        small_number = number1;
    else{
        small_number = number2;
    }
    divisor[0] = 0;
    for(i = 1 ; i < maxn ; i++){
        divisor[i] = divisor[i - 1] + 1;
        common[i] = 0;
    }
    int j = 1;
    for(i = 1 ; i <= small_number ; i++){
        if(number1 % divisor[i] == 0 && number2 % divisor[i] == 0){
            common[j] = divisor[i];
            j++;
        }
    }
    int ans = common[1];
    for(i = 1 ; i <= j ; i++){
        if(ans < common[i]){
            ans = common[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}