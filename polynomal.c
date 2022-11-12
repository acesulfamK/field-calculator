#include<stdio.h>
#include<math.h>

#define MAX_DIM 10
#define MAX_COEF_FIELD_SIZE 100

struct polynomial {
	int dim; //次元(valueのlen)
	int value[MAX_DIM]; //係数列(昇順)
};

struct polynomial poly_reduc(int p,struct polynomial x);
struct polynomial poly_mul(struct polynomial x,struct polynomial y); 
struct polynomial poly_residue(struct polynomial y,struct polynomial x); // y/xを表す。
void print_poly(struct polynomial x);

int main(){
	struct polynomial b =  {2,{1,3}};
	struct polynomial x = {1,{1}};
	struct polynomial f = {3,{1,1,1}};
	int i;
	for(i=0;i<30;i++){
		x = poly_mul(x,b);
		x = poly_residue(x,f);
		x = poly_reduc(5,x);
		printf("%d  :  ",i);
		
		print_poly(x);
	}
	return 0;
}



struct polynomial poly_residue(struct polynomial y,struct polynomial x){
	int i,j;
	int quot;
	
	for(i = y.dim - x.dim;i >= 0 ;i--){
		quot = y.value[i + x.dim - 1]/x.value[x.dim - 1];
		for(j = 0;j<x.dim;j++){
			y.value[i+j] -= quot*x.value[j];
		}
	}
	for(i = y.dim - 1 ; i>=0;i--){
		if(y.value[i]!=0){
			y.dim = i + 1;
			return y;
		}
	}
	y.dim = 0;
	return y;
}




struct polynomial poly_reduc(int p,struct polynomial x){
	int i;
	for(i = 0;i<x.dim;i++){
		x.value[i] = (x.value[i]%p+p)%p;
	}
	return x;
}



struct polynomial poly_mul(struct polynomial x,struct polynomial y){
	struct polynomial ans;	
	int i,j;
	for(i = 0;i<MAX_DIM;i++){
		ans.value[i] = 0;
	}
	ans.dim = (x.dim-1)+(y.dim-1)+1;
	for(i = 0;i<x.dim;i++){
		for(j = 0;j<y.dim;j++){
			ans.value[i+j] += x.value[i]*y.value[j];
		}
	}
	return ans;
}



void print_poly(struct polynomial x){
	int i;
	printf("[");
	for(i=0;i<x.dim;i++){
		printf("%d,",x.value[i]);
	}
	printf("]\n");
	return;	
}