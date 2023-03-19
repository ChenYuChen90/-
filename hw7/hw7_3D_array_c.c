#include<stdio.h>
#include<stdlib.h>
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k);
void delete_3d_array(unsigned ***arr);

unsigned random_seed=7122;
unsigned Random(){
	return random_seed=random_seed*0xdefaced+1;
}
int main(){
	int n,m,k,_;
	scanf("%d%d%d%d%u",&_,&n,&m,&k,&random_seed);
	while(_--){
		unsigned ***arr=new_3d_array(n,m,k);
		int i,j,l;
		for(i=0;i<n;++i){
			for(j=0;j<m;++j){
				for(l=0;l<k;++l){
					arr[i][j][l]=Random();
				}
			}
		}
		for(i=0;i<5;++i){
			unsigned a,b,c;
			a=Random()%n;
			b=Random()%m;
			c=Random()%k;
			if(i)putchar(' ');
			printf("%u",arr[a][b][c]);
		}
		puts("");
		delete_3d_array(arr);
	}
	return 0;
}

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned dim_2D = n*m;
    unsigned dim_3D = dim_2D*k;
    unsigned ***p3 = (unsigned***)malloc(n*sizeof(unsigned**)); // allocate an array of size n which contains n unsigned**
    unsigned **p2 = (unsigned**)malloc(dim_2D*sizeof(unsigned*)); // allocate an array of size n*m which contains n*m unsigned*
    unsigned *p1 = (unsigned*)malloc(dim_3D*sizeof(unsigned)); // allocate the memory for all n*m*k elements
    for(unsigned i = 0; i < n; i++){
        *(p3+i) = p2+i*m;
        for(unsigned j = 0; j < m; j++){
            *(p2+i*m+j) = p1+i*m*k+j*k;
        }
    }
    return p3;
}
// where you malloc where u free
void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
    return;
}