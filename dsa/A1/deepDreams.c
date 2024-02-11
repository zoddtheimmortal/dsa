#include <stdio.h>
#include<gmp.h>

int main(){
	mpz_t a;
	mpz_init(a);
	gmp_scanf("%Zd",a);

	mpz_t zero;
	mpz_init_set_ui(zero,0);

	while(mpz_cmp_ui(a,0)){
		if(!mpz_divisible_ui_p(a,2)){
			mpz_add_ui(zero,zero,1);
		}
		mpz_fdiv_q_ui(a,a,2);
	}

	mpz_out_str(stdout,10,zero);
	printf("\n");
	mpz_clear(zero);
}