#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define N 1e6

int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}

char* lcm_str(char* a,char* b){
	int len_a=strlen(a),len_b=strlen(b);
	int gcd_len=gcd(len_a,len_b);

	char* pattern=(char*) malloc(sizeof(char)*gcd_len);
	strncpy(pattern,a,gcd_len);

	for(int i=0;i<len_a;i++){
		if(a[i]!=pattern[i%gcd_len]) return "-1";
	}

	for(int i=0;i<len_b;i++){
		if(b[i]!=pattern[i%gcd_len]) return "-1";
	}

	int lcm_len=(len_a*len_b)/gcd_len;
	char* lcm=(char*) malloc(sizeof(char)*lcm_len);
	for(int i=0;i<lcm_len;i++){
		lcm[i]=pattern[i%gcd_len];
	}

	free(pattern);
	return lcm;
}

int main(){
	char* a=(char*) malloc(sizeof(char)*N);
	char* b=(char*) malloc(sizeof(char)*N);
	scanf("%s",a); scanf("%s",b);

	char* lcm=lcm_str(a,b);
	printf("%s\n",lcm);

	free(a); free(b);
}