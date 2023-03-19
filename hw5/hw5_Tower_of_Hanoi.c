#include <stdio.h> //Ok
void hanoi(int n, char A, char C, char B);
         //disk   from    target  buffer 
int main(void){
    int n; scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

void hanoi(int n, char A, char C, char B){
    //basis step
    if(n == 1) {printf("move disk %d from rod %c to rod %c\n", n, A, C); return ;} // 記得做 return
    //recursive step
    hanoi(n - 1, A, B, C); // n - 1 先放到 buffer
    printf("move disk %d from rod %c to rod %c\n", n, A, C); // 最後一個
    hanoi(n - 1, B, C, A); // 把 n - 1 從 buffer 放到 target
}