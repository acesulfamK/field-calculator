# polynomial-calculator

```c
struct polynomial {
	int dim; //次元(valueのlen)
	int value[MAX_DIM]; //係数列(昇順)
};
```

多項式を表現する構造体。dim は多項式の最高次数+1 を表し(これは、係数体からの拡大と見たときに元の拡大次数を表す。)、
value は index 次の項の係数を格納している。

```c
struct polynomial poly_reduc(int p,struct polynomial x); //係数を係数体の元で表す。今回は素体のみ対応。
struct polynomial poly_mul(struct polynomial x,struct polynomial y); // 多項式同士の積を表している。
struct polynomial poly_residue(struct polynomial y,struct polynomial x); // y/xを表す。
void print_poly(struct polynomial x); // 多項式を数列の形で出力する。
```

# rational-calculator

## struct ratinoal x

有理数を定義している型。分子は x.num、分母は x.den である。

## rational_add();

足し算

## rational_sub();

引き算

## rational_mul();

掛け算

## rational_div();

割り算

## int rational_eq(struct rational x,struct rational y)

等しいかを比較する。

## int rational_reduction(struct rational,struct rational y)

約分を行う。ユークリッドの互除法を用いている。
