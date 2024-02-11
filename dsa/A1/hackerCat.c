#include<stdio.h>
#include<gmp.h>

int main(){
	mpz_t n;
	mpz_init(n);
	gmp_scanf("%Zd",n);

	mpz_t m;
	mpz_init(m);
	gmp_scanf("%Zd",m);

	mpz_t op;
	mpz_init(op);
	mpz_invert(op,n,m);

	mpz_out_str(stdout,10,op);
	printf("\n");
	mpz_clear(op);

}