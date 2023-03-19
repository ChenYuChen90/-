#include <stdlib.h>

unsigned*** new_3d_array(unsigned n, unsigned m, unsigned k){
    unsigned large_2d = n * m;
    unsigned large_3d = large_2d * k;
    // malloc需要的空間
    unsigned ***p3 = (unsigned***)malloc(n * sizeof(unsigned**));       // 最外層
    unsigned **p2 = (unsigned**)malloc(large_2d * sizeof(unsigned*));   // 第二層
    unsigned *p1 = (unsigned*)malloc(large_3d * sizeof(unsigned));      // 最內層
    
    // 最外層的陣列需要儲存address指向第二層的位置
    for(unsigned i = 0 ; i < n ; i++){
        // p3[i] = p2[i*m][0]
        *(p3+i) = p2+i*m;

        // 第二層的陣列需要儲存address指向最內層的位置
        for(unsigned j = 0 ; j < m ; j++){
            // p2[i*m][j] = p1[i*m*k][j*k][0]
            *(p2+i*m+j) = p1+i*m*k+j*k;
        }
    }
    return p3;
}

void delete_3d_array(unsigned ***arr){
    // 從最內層向外清空
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
    return;
}