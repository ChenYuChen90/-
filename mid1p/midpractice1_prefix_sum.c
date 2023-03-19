#include <stdio.h> //Ok
//在輸入時就先開一個和的陣列
int main(){
    int n, i; scanf("%d", &n);
    unsigned long long number[n], sum[n];
    for(i = 0 ; i <= n ; i ++) number[i] = 0, sum [i] = 0;
    for(i = 1 ; i <= n ; i++){
        scanf("%d", &number[i]);
        sum[i] = sum[i - 1] + number[i];
    }
    int q; scanf("%d", &q);
    while(q--){
        int l, r; scanf("%d %d", &l, &r);
        unsigned long long ans = 0;
        ans = sum[r] - sum[l - 1];
        printf("%llu\n", ans);
    }
    return 0;
}
