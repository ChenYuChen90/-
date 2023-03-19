#include <stdio.h>

void move(int dir, int board[4][4]){
    switch(dir){
        case 0: //up
            for(int j = 0; j < 4; j++){
                for(int i = 3; i >= 0; i--){
                    if(board[i][j] == 0){
                        for(int k = i; k < 3; k++){
                            board[k][j] = board[k+1][j];
                        }
                        board[3][j] = 0;
                    }
                }
            }
            break;
        case 1: // down
            for(int j = 0; j < 4; j++){
                for(int i = 0; i < 4; i++){
                    if(board[i][j] == 0){
                        for(int k = i; k > 0; k--){
                            board[k][j] = board[k-1][j];
                        }
                        board[0][j] = 0;
                    }
                }
            }
            break;
        case 2: // left
            for(int i = 0; i < 4; i++){
                for(int j = 3; j >= 0; j--){
                    if(board[i][j] == 0){
                        for(int k = j; k < 3; k++){
                            board[i][k] = board[i][k+1];
                        }
                        board[i][3] = 0;
                    }
                }
            }
            break;
        case 3: // right
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    if(board[i][j] == 0){
                        for(int k = j; k > 0; k--){
                            board[i][k] = board[i][k-1];
                        }
                        board[i][0] = 0;
                    }
                }
            }
            break;
    }
}

void merge(int dir, int board[4][4]){
    switch(dir){
        case 0: //up
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 4; j++){
                    if(board[i][j] == board[i+1][j]){
                        board[i][j] *= 2;
                        board[i+1][j] = 0;
                    }
                }
            }
            break;
        case 1: // down
            for(int i = 3; i > 0; i--){
                for(int j = 0; j < 4; j++){
                    if(board[i][j] == board[i-1][j]){
                        board[i][j] *= 2;
                        board[i-1][j] = 0;
                    }
                }
            }
            break;
        case 2: // left
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 3; j++){
                    if(board[i][j] == board[i][j+1]){
                        board[i][j] *= 2;
                        board[i][j+1] = 0;
                    }
                }
            }
            break;
        case 3: // right
            for(int i = 0; i < 4; i++){
                for(int j = 3; j > 0; j--){
                    if(board[i][j] == board[i][j-1]){
                        board[i][j] *= 2;
                        board[i][j-1] = 0;
                    }
                }
            }
            break;
    }
}
int same(int a[4][4], int b[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}
int main() {
    int a[4][4], b[4][4];
    while(scanf("%d", &a[0][0]) != EOF) {
        b[0][0] = a[0][0];
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(i == 0 && j == 0)continue;
                scanf("%d", &a[i][j]);
                b[i][j] = a[i][j];
            }
        }
        for(int k = 0; k < 4; k++) {
            move(k, b);
            merge(k, b);
            move(k, b);
            if(same(a, b)) printf("Invalid\n");
            else {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        printf("%d", b[i][j]);
                        if(j == 3) printf("\n");
                        else printf(" ");
                        b[i][j] = a[i][j];
                    }
                }
            }
        }
    }
}