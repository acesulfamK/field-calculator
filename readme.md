# polynomial.c

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

# rational.h

有理数の計算をするライブラリ

```c
// rational io
void print_rational(struct rational x); // 有理数を定義している型。分子は x.num、分母は x.den である。
// rational calc
int rational_eq(struct rational x,struct rational y); // 等しいければ0,そうでなければ1を返す
struct rational rational_add(struct rational x,struct rational y); // 足し算
struct rational rational_sub(struct rational x,struct rational y); // 引き算
struct rational rational_div(struct rational x,struct rational y); //掛け算
struct rational rational_mul(struct rational x,struct rational y); // 割り算
struct rational rational_reduction(struct rational x); // 約分を行う (コードはユークリッドの互除法)
```
