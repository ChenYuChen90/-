#include <stdio.h> //Ok
#include <math.h>
// 要注意 x 跟 y 用來定出每格的位置
char carpet[3000][3000] = {0};
void sierpinski(int size, int y, int x);

int main(void){
    int n; scanf("%d", &n);
    int size = pow(3, n);
    int i, j;
    for(i = 0 ; i < size ; i++) for(j = 0 ; j < size ; j++) carpet[i][j] = '.';
    // 從最大的開始把中間填滿
    // 然後從左上開始分格填入下一階層的
    sierpinski(size, 0, 0);
    for(i = 0 ; i < size ; i++) for(j = 0 ; j < size ; j++) 
        j == size - 1 ? printf("%c\n", carpet[i][j]) : printf("%c", carpet[i][j]);
    return 0;
}

void sierpinski(int size, int y, int x){
    if(size < 3) return ;
    // 3的倍數格為一區
    int block = size / 3;
    int i, j;
    // 將最中間填為 #
    // y 跟 x 是用來定位的可以找出每一區的中心
    for(i = block + y ; i < 2*block + y ; i++) for(j = block + x ; j < 2*block + x ; j++)
        carpet[i][j] = '#';
    // 接著將剩餘8格依同樣方法操作
    // y 跟 x 是用來定位
    // 注意要 <=
    for(i = y ; i <= 2*block + y ; i += block) for(j = x ; j <= 2*block + x ; j += block)
        if(i != block || j != block) sierpinski(block, i, j);
}