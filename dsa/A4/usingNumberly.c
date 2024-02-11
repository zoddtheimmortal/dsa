#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ll long long int

void word_num(ll n){
	if(n==0){
		printf("zero");
		return;
	}

	ll lim=1e12,hun=0,t=0;

	char mul[][10]={
		"","trillion","billion","million","thousand"
	};
	char twin[][10]={
		"","one","two","three","four","five","six","seven","eight","nine","ten",
		"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen",
		"nineteen"
	};
	char ten[][10]={
		"","twenty","thiry","forty","fifty","sixty","seventy","eighty",
		"ninety"
	};

	if(n<20){
		printf("%s",twin[n]);
		return;
	}

	for(ll i=n;	i>0;i%=lim,lim/=1000){
		hun=i/lim;

		while(hun==0){
			i%=lim;
			lim/=1000;
			hun=i/lim;
			t++;
		}

		if(hun>99){
			printf("%s hundred ",twin[hun/100]);
		}
		hun%=100;

		if(hun>0 && hun<20) printf("%s ",twin[hun]);
		else if(hun%10==0 && hun!=0) printf("%s ",ten[(hun/10)-1]);
		else if(hun>20 && hun<100){
			printf("%s %s ",ten[(hun/10)-1],twin[hun%10]);
		}

		if(t<4) printf("%s ",mul[++t]);
	}


}

int main(){
	ll n; scanf("%lld",&n);
	word_num(n);
	printf("\n");
}