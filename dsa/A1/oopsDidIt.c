#include <stdio.h>
#include <gmp.h>

int main(){
	char a[100000],b[100000];
	scanf("%s %s",a,b);

	mpz_t a1,b1,c;
	mpz_init(a1); mpz_init(b1);
	mpz_set_ui(a1,0); mpz_set_ui(b1,0);

	mpz_set_str(a1,a,10);
	mpz_set_str(b1,b,10);

	mpz_mul(c,a1,b1);

	mpz_out_str(stdout,10,c);
	mpz_clear(c);
	printf("\n");
}