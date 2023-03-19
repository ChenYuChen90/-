#include <stdio.h> //Ok
int main(){
    int n; scanf("%d", &n);
    char str[n], step[n]; scanf("%s", str);
    int q; scanf("%d", &q);
    while(q--){
        int a, b, sz; scanf("%d %d %d", &a, &b, &sz);
        int i, j;
        long long int ans1 = 0, ans2 = 0;
        // 數字有可能會是兩個9位數相乘設long long int
        // 記得設 = 0 重置每次的值
        for(i = a, j = b ; i < a + sz ; i++, j++){
            // ex : 123 = 0 * 10 + 1 -> 1 * 10 + 2 -> 12 * 10 + 3 
            ans1 *= 10;
            ans1 += str[i] - '0';
            ans2 *= 10;
            ans2 += str[j] - '0';
            str[i] = str[j] = 0; // 清空
        }
        printf("%lld\n", ans1 * ans2);
        for(i = 0, j = 0 ; i < n ; i++, j++){
            while(str[i] == 0) i++;
            // 只能用while不能用if
            // 在有0連續的狀況 用if 還是有0還是會被留下
            step[j] = str[i];
        }
        // 要記得重置
        n -= sz * 2; //字串少兩倍sz
        for(i = 0 ; i < n ; i++) str[i] = step[i]; // 重置str[]
    }
    return 0;
}