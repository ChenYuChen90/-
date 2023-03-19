#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b){
    int x = *(int*)a;
    int y = *(int*)b;
    if(x < y) return 1;
    if(x == y) return 0;
    return -1;
}

#define maxn 100005
int arr[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    qsort(arr+1, n, sizeof(int),cmp);
    for(int i=1;i<=n;i++) {
        if(i != 1)	printf(" ");
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}