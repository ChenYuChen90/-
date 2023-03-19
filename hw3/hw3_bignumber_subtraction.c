#include <stdio.h>
#include <string.h>
int main(void){
	char arr1[100] = {}, arr2[100] = {};
	int num1[100] = {}, num2[100] = {}, arr3[100] = {};
	int i, j, d;
	int a; scanf("%d", &a);
	getchar();
	for(i = 0 ; i < a ; i++) arr1[i] = getchar();
	int b; scanf("%d", &b);
	getchar();
	for(i = 0 ; i < b ; i++) arr2[i] = getchar();
	int k = strcmp(arr1, arr2);
	if((a < b) || (a == b) && k == -1){
		for(i = 0 ; i < 100 ; i++)
			arr3[i] = arr2 [i], arr2[i] = arr1[i], arr1[i] = arr3[i];
	d = b, b = a, a = d;
	printf("-");
	}
	for(i = 0 ; i < a ; i++) num1[i] = arr1[(a - 1) - i] - '0';
	for(i = 0 ; i < b ; i++) num2[i] = arr2[(b - 1) - i] - '0';
	for(i = 0 ; i < a ; i++){
		num1[i] -= num2[i];
		if(num1[i] < 0) num1[i] += 10, num1[i + 1]--; 
	}
	for(j = 99 ; j >= 0 ; j--) if(num1[j] != 0) break;
	if(j < 0) printf("0");
	for( ; j >= 0 ; j--) printf("%d", num1[j]);
	return 0;
}