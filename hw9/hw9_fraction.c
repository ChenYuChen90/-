#include <stdio.h>

typedef struct {
	long long numerator; 
	long long denominator; 
} Fraction;

Fraction CreateFrac(long long, long long);
void Reduction(Fraction*);
Fraction Add(Fraction, Fraction);
Fraction Sub(Fraction, Fraction);
Fraction Mul(Fraction, Fraction);
Fraction Div(Fraction, Fraction);
int Compare(Fraction, Fraction);
long long GCD(long long a, long long b);

Fraction CreateFrac(long long a, long long b){
	return (Fraction){
		.numerator = a,
		.denominator = b
	};
}
void Reduction(Fraction* a){
	long long gcd = GCD(a->numerator, a->denominator);
	a->denominator /= gcd;
	a->numerator /= gcd;
}
Fraction Add(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	a.denominator *= b.denominator;
	a.numerator += b.numerator;
	Reduction(&a);
	return a;
}
Fraction Sub(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	a.denominator *= b.denominator;
	a.numerator -= b.numerator;
	Reduction(&a);
	return a;
}
Fraction Mul(Fraction a, Fraction b){
	a.numerator *= b.numerator;
	a.denominator *= b.denominator;
	Reduction(&a);
	return a;
}
Fraction Div(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	a.denominator *= b.numerator;
	Reduction(&a);
	return a;
}
int Compare(Fraction a, Fraction b){
	Reduction(&a);
	Reduction(&b);
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	return a.numerator > b.numerator ? 1 : 0;
}
long long GCD(long long a, long long b){
	if(b == 0) return a;
	return GCD(b, a%b);
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int type, p1, q1, p2, q2;
		scanf("%d %d/%d %d/%d", &type, &p1, &q1, &p2, &q2);
		Fraction f1 = CreateFrac(p1, q1), f2 = CreateFrac(p2, q2), ans;
		switch (type) {
			case 0: 
				ans = Add(f1, f2);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 1: 
				ans = Compare(f1, f2) ? Sub(f1, f2) : Sub(f2, f1);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 2: 
				ans = Mul(f1, f2);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 3: 
				ans = Div(f1, f2);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 4:
				Reduction(&f1), Reduction(&f2);
				printf("%lld/%lld %lld/%lld\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
				break;
		}
	}
}
