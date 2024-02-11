#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gmp.h>

int main(){
	mpz_t a; mpz_t b;
	mpz_init(a); mpz_init(b);
	gmp_scanf("%Zd %Zd",a,b);

	mpz_t c; mpz_init(c);

	mpz_mul(c,a,b);

	gmp_printf("%Zd\n",c);
}