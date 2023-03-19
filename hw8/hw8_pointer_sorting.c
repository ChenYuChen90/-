#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int** s(int* a,int len);

int main() {
	int len;
	int **ans;
	
	scanf("%d", &len);
	
	int *a = (int*)malloc(len * sizeof(int));

	for (int i = 0;i < len;i++) {
		scanf("%d", &a[i]);
	}

	ans = s(a,len);

	for (int i = 0;i < (int)sqrt(len);i++) {
		for (int j = 0;j < (int)sqrt(len);j++) {
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	
	free(a);
	return 0;
}

int** s(int* a,int len){
    // any sorting solution
    int i, j, temp;
    for(i = 0 ; i < len - 1 ; i++){
        for(j = 0 ; j < len - 1 - i ; j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    len = sqrt(len);
    //link the 1D array into a 2D array
    int **dim2arr = (int**)malloc(len * sizeof(int*));
    for(int i = 0; i < len; i++)
        dim2arr[i] = a + i*len;
    return dim2arr;
}
