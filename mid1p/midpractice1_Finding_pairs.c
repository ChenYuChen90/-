#include <stdio.h> //Ok
int main(){
    int n, i, x; scanf("%d", &n);
    long long ans = 0, counter[10005] = {};
    for(i = 0 ; i < n ; i++){
        // 輸入時直接把那個數字的陣列當作計次計算
		// 就不用先輸入數字，在跑數字出現幾次
        scanf("%d", &x);
        counter[x]++;
    }
    for(i = 0 ; i <= 10000 ; i++)
        // 如果要一個式子運算counter[]要設為long long
        ans += (counter[i]*(counter[i] - 1))/2;
        // 就是C幾取2的意思
    printf("%lld\n", ans);
    return 0;
}