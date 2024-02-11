#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <gmp.h>

int main(){
	mpz_t a,b; mpz_init(a); mpz_init(b);
	gmp_scanf("%Zd %Zd",a,b);

	mpz_mul(a,a,b);

	gmp_printf("%Zd\n",a);
}