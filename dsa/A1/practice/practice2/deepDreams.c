#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <gmp.h>

int main(){
	mpz_t a; mpz_init(a);
	gmp_scanf("%Zd",a);

	mpz_t one; mpz_init_set_ui(one,0);

	while(mpz_cmp_ui(a,0)){
		if(!mpz_divisible_ui_p(a,2)) mpz_add_ui(one,one,1);
		mpz_fdiv_q_ui(a,a,2);
	}

	gmp_printf("%Zd\n",one);
}