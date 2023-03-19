// 選或不選問題
#include <stdio.h>
int n, max_w, beg_w[30], beg_v[30];
long long ans = 0;
void kca(int step, int cor_weight, long long cor_value);

int main(){
    scanf("%d%d", &n, &max_w);
    for(int i = 1 ; i <= n ; i++) scanf("%d%d", &beg_w[i], &beg_v[i]);
    kca(1, 0, 0);
    printf("%lld\n", ans);
}

void kca(int step, int cor_w, long long cor_v){
    if(step == n + 1){
        if(cor_v > ans) ans = cor_v;
        return;
    }
    for(int i = 0 ; i < 2 ; i++){
        // 不選就跳到下一格
        if(i == 0) kca(step + 1, cor_w, cor_v);
        // 選下那一格
        else if(i == 1){
            // 如果重量超過 return
            if(cor_w + beg_w[step] > max_w) return;
            else kca(step + 1, cor_w + beg_w[step], cor_v + beg_v[step]);
        }
    }
}