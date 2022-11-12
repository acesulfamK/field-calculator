#ifndef RATIONAL_H
#define RATIONAL_H

#include<stdio.h>

struct rational {
	int num;
	int den;
};

// rational io
void print_rational(struct rational x);


// rational calc
int rational_eq(struct rational x,struct rational y);
struct rational rational_add(struct rational x,struct rational y);
struct rational rational_sub(struct rational x,struct rational y);
struct rational rational_div(struct rational x,struct rational y);
struct rational rational_mul(struct rational x,struct rational y);
struct rational rational_reduction(struct rational x);


struct rational rational_reduction(struct rational x){
	int a = x.num;
	int b = x.den;
	struct rational ans;

	while( a != 0 && b != 0){
		if(a<b){
			b = b % a;
		} else {
			a = a % b;
		}
	}
	// a+bは最大最大公約数となる(aとbのどちらかが最大公約数で、もう一方には0が入っている。)
	ans.num = x.num/(a+b);
	ans.den = x.den/(a+b);

	return ans;
}


struct rational rational_mul(struct rational x,struct rational y){
	struct rational ans = {x.num*y.num, y.den*x.den};
	return ans;
}


struct rational rational_div(struct rational x,struct rational y){
	if(y.num == 0){
		printf("error: you can't divide some number by 0\n");
	}
	struct rational ans = {x.num*y.den, y.num*x.den};
	return ans;
}

int rational_eq(struct rational x,struct rational y){
	if(x.den*y.num - x.num*y.den == 0 ){
		return 0;
	} else {
		return 1;
	}
}

void print_rational(struct rational x){
	printf("%d/%d\n",x.num,x.den);
}	

struct rational rational_sub(struct rational x, struct rational y){
	struct rational ans;
	ans.num = y.den*x.num-y.num*x.den;
	ans.den = y.den*x.den;
	return ans;
}

struct rational rational_add(struct rational x, struct rational y){
	struct rational ans;
	ans.num = y.den*x.num+y.num*x.den;
	ans.den = y.den*x.den;
	return ans;
}

#endif