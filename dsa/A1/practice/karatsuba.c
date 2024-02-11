#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int makeEqual(char* a,char* b){
	int l1=0,l2=0,len=0;
	while(a[l1]!='\0') l1++;
	while(b[l2]!='\0') l2++;

	len=max(l1,l2);

	char* x=(char*) malloc(sizeof(char)*100000);
	char* y=(char*) malloc(sizeof(char)*100000);

	int i=0,j=0,m=0,n=0;

	while(i<len-l1) x[i++]='0';
	while(j<len-l2) y[j++]='0';

	while(i<len) x[i++]=a[m++];
	while(j<len) y[j++]=b[n++];

	i=0,j=0;
	while(i<len) a[i++]=x[i];
	while(j<len) b[j++]=y[j];

	free(x); free(y);
	a[i++]='\0'; b[j++]='\0';

	return len;
}

char* digitAdd(char* a,char* b){
	int len=makeEqual(a,b);

	char* c=(char*) malloc(sizeof(char)*100000);

	int sum=0,carry=0,i=0;

	while(len-1>=0){
		int temp=(a[len-1]-'0')+(b[len-1]-'0')+carry;
		sum=temp%10;
		carry=temp/10;
		c[i++]=sum+'0';
		len--;
	}

	if(carry>0) c[i++]=carry+'0';

	for(int j=0;j<i/2;j++){
		char t=c[j];
		c[j]=c[i-j-1];
		c[i-j-1]=t;
	}

	c[i++]='\0';
	return c;
}

char* sub_str(char* a,int si,int ei){
	int m=0;
	char* sub=(char*) malloc(sizeof(char)*200000);

	for(int i=si;i<ei;i++){
		sub[m++]=a[i];
	}

	sub[m++]='\0';
	return sub;
}

void appendZeroes(char* a,int zero){
	int l1=0;
	while(a[l1]!='\0') l1++;

	while(zero--) a[l1++]='0';
	a[l1++]='\0';
	return;
}

char* karatsuba(char* a,char* b){
	int n=makeEqual(a,b);

	if(n==1){
		char* z=(char*) malloc(sizeof(char)*200000);
		int temp=(a[0]-'0')*(b[0]-'0');
		z[1]=temp%10+'0';
		z[0]=temp/10+'0';
		z[2]='\0';
		return z;
	}

	char* a_l=sub_str(a,0,n/2); //a
	char* a_r=sub_str(a,n/2,n);	//b

	char* b_l=sub_str(b,0,n/2);	//c
	char* b_r=sub_str(b,n/2,n);	//d

	char* ac=karatsuba(a_l,b_l);
	char* ad=karatsuba(a_l,b_r);

	char* bc=karatsuba(a_r,b_l);
	char* bd=karatsuba(a_r,b_r);

	char* adbc=digitAdd(ad,bc);

	free(a_l); free(a_r); free(b_l); free(b_r);

	appendZeroes(ac,n);
	appendZeroes(adbc,n/2);

	char* p=digitAdd(ac,adbc);
	char* q=digitAdd(p,bd);

	free(ac); free(ad); free(adbc); free(bc); free(bd); free(p);
	return q;
}

char* trim(char* c){
	while(c[0]=='0' && c[1]!='\0') c++;
	return c;
}

int main(){
	char* a=(char*) malloc(sizeof(char)*100000);
	char* b=(char*) malloc(sizeof(char)*100000);

	scanf("%s %s",a,b);

	char* c=karatsuba(a,b);
	c=trim(c);

	printf("%s\n",c);
}