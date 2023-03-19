#include <stdio.h>
char tar[1000005], type[10];
char inp[1000005];

int main(void){
    int i = 1;
    // wrong 計算錯誤有幾個
    int wrong = 0, correct = 1;
    fgets(tar + 1, 500005, stdin);
    while(fgets(type, 5, stdin) != NULL){
        if(type[0] == '\\'){
            // 刪除的時候 如果刪除的部分原本是錯的 錯誤數要減一
            if(tar[i - 1] != inp[i - 1]) wrong--;
            i = i == 1 ? 1 : i - 1;
        }
        else{
            inp[i] = type[0];
            if(tar[i] != inp[i]) wrong++;
            i++;
        }
        // 錯誤數不是0就算錯誤
        if(wrong) puts("0");
        else puts("1");
    }
    for(int i = 1 ; tar[i] != '\n' ; i++) if(tar[i] != inp[i])
        correct = 0;
    printf("%s\n", correct && !wrong ? "Correct" : "Incorrect");
    return 0;
}