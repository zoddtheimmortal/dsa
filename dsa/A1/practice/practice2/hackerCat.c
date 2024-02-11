#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <gmp.h>

int main(){
	mpz_t a; mpz_t b; mpz_t c;
	mpz_init(a); mpz_init(b); mpz_init(c);

	gmp_scanf("%Zd %Zd",a,b);

	mpz_invert(c,a,b);

	gmp_printf("%Zd\n",c);
}