#include <stdio.h>
#include <string.h>
int main(void){
    char number[105];
    int i, j, length;
    scanf("%s", number);
    length = strlen(number);
    for( i = 0 ; i < length ; i++){
        if(number[i] != '0' && number[i] != '1' && number[i] != '6' && number[i] != '8' && number[i] != '9'){
            printf("No\n");
            return 0;
        }
    }
    for( j = length - 1; j >= 0 ; j--){
        if(number[j] != '0'){
            break;
        }
    }
    for(i = j ; i >= 0 ; i--){
        switch(number[i]){
            case '0':
                printf("0");
                break;
            case '1':
                printf("1");
                break;
            case '6':
                printf("9");
                break;
            case '8':
                printf("8");
                break;
            case '9':
                printf("6");
                break;
        }
    }
    printf("\n");
    return 0;
}