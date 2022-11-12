#include<stdio.h>
#include "rational.h"

int main(){
	struct rational x = {1,3};
	struct rational y = {1,4};
	

	struct rational z = rational_add(x,y);
	struct rational a = rational_sub(x,y);
	int b = rational_eq(x,y);
	struct rational c = rational_div(x,y);
	struct rational d = rational_mul(x,y);
	struct rational e = rational_add(x,x);
	struct rational f = rational_reduction(x);



	print_rational(x);
	print_rational(z);
	print_rational(a);
	print_rational(c);
	print_rational(d);
	printf("%d\n",b);
	print_rational(e);
	print_rational(f);
	return 0;
}
