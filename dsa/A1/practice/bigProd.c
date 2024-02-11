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

	free(x); free(y);

	a[i++]='\0'; b[j++]='\0';
	return len;
}

int main(){
	char* a=(char*) malloc(sizeof(char)*1000);
	char* b=(char*) malloc(sizeof(char)*1000);

	int len=makeEqual(a,b);

	scanf("%s %s",a,b);


}