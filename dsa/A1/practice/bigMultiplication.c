#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int makeEqual(char* a,char* b){
	int l1=0,l2=0,len=0;
	while(a[l1]!='\0') l1++;
	while(b[l2]!='\0') l2++;

	len=max(l1,l2);

	char* x=(char*) malloc(sizeof(char)*1000);
	char* y=(char*) malloc(sizeof(char)*1000);
	int i=0,j=0,m=0,n=0;
	while(i<len-l1) x[i++]='0';
	while(j<len-l2) y[j++]='0';

	while(i<len) x[i++]=a[m++];
	while(j<len) y[j++]=b[n++];

	i=0,j=0;
	while(i<len) a[i++]=x[i];
	while(j<len) b[j++]=y[j];

	a[i++]='\0'; b[j++]='\0';

	free(x); free(y);

	return len;
}

char* digitAdd(char* a,char* b){
	int len=makeEqual(a,b);

	char* c=(char*) malloc(sizeof(char)*1000);
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

void appendZeros(char* a,int zero){
	int l1=0;
	while(a[l1]!='\0') l1++;

	while(zero--){
		a[l1++]='0';
	}

	a[l1++]='\0';
}

char* digitMult(char* a,char b){
	int l1=0;
	while(a[l1]!='\0') l1++;

	char* c=(char*) malloc(sizeof(char)*1000);
	int mult=0,carry=0,i=0;
	while(l1-1>=0){
		int temp=(a[l1-1]-'0')*(b-'0')+carry;
		mult=temp%10;
		carry=temp/10;
		c[i++]=mult+'0';
		l1--;
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

char* trim(char* a){
	while(a[0]=='0' && a[1]!='\0'){
		a++;
	}

	return a;
}

char* multiply(char* a,char* b){
	int len=makeEqual(a,b);
	int zero=0;

	char* ans=(char*) malloc(sizeof(char)*2000);
	ans[0]='0',ans[1]='\0';
	for(int i=len-1;i>=0;i--){
		char* temp=digitMult(a,b[i]);
		appendZeros(temp,zero);
		ans=digitAdd(ans,temp);
		zero++;
	}

	return trim(ans);
}

int main(){
	char* a=(char*) malloc(sizeof(char)*1000);
	char* b=(char*) malloc(sizeof(char)*1000);

	scanf("%s %s",a,b);

	char* c=multiply(a,b);

	printf("%s\n",c);
	free(a); free(b); free(c);
}