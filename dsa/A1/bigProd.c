#include <stdio.h>

#define len(x,arr) while(arr[x]!='\0') (x)++
#define max(a,b) ((a>b)?(a):(b))

void makeEqual(char a[],char b[],int lA,int lB){
	int len=max(lA,lB);
	char z1[1000],z2[1000];

	int i=0,j=0;

	while(i<len-lA) z1[i++]='0';
	while(j<len-lB) z2[j++]='0';

	int m=0,n=0;
	while(i<len){
		z1[i++]=a[m++];
	}

	while(j<len){
		z2[j++]=b[n++];
	}

	for(int i=0;i<len;i++){
		a[i]=z1[i];
	}

	for(int j=0;j<len;j++){
		b[j]=z2[j];
	}

	a[len]='\0';
	b[len]='\0';
}

void addStrings(char a[],char b[],char c[],int lA,int lB){
	makeEqual(a,b,lA,lB);

	int sum=0,carry=0,len=(max(lA,lB)-1),i=0;

	while(len>=0){
		sum=((a[len]-'0')+(b[len]-'0')+carry)%10;
		carry=((a[len]-'0')+(b[len]-'0')+carry)/10;
		c[i++]=sum+'0';
		len--;
	}

	if(carry>0) c[i++]=carry+'0';

	for(int j=0;j<i/2;j++){
		char temp=c[j];
		c[j]=c[i-j-1];
		c[i-j-1]=temp;
	}

	c[i++]='\0';
}

void singleMult(char a[],char b,char c[],int lA,int lB){

	int mult=0,carry=0,len=(max(lA,lB)-1),i=0;

	while(len>=0){
		mult=((a[len]-'0')*(b-'0')+carry)%10;
		carry=((a[len]-'0')*(b-'0')+carry)/10;
		c[i++]=mult+'0';
		len--;
	}

	if(carry>0) c[i++]=carry+'0';

	for(int j=0;j<i/2;j++){
		char temp=c[j];
		c[j]=c[i-j-1];
		c[i-j-1]=temp;
	}

	c[i++]='\0';
}

void appendZeros(char a[],int lA,int zero){
	int i=0;
	while(zero--){
		a[lA+i]='0';
		i++;
	}
	a[lA+i]='\0';
	i++;
}

void multStrings(char a[],char b[],char c[],int lA,int lB){
	makeEqual(a,b,lA,lB);
	int zero=0,len=max(lA,lB),i=0;
	char temp[2000],prev[2000]="0";

	while(len-1>=0){
		singleMult(a,b[len-1],temp,lA,1);
		int tLen=0; len(tLen,temp);
		appendZeros(temp,tLen,zero);
		len(tLen,temp);
		int tPrev=0; len(tPrev,prev);
		addStrings(prev,temp,c,tPrev,tLen);
		int cLen=0; len(cLen,c);
		for(int i=0;i<cLen;i++){
			prev[i]=c[i];
		}
		prev[cLen]='\0';
		len--;
		zero++;
	}

	len(i,c); c[i++]='\0';

	while(c[0]=='0' && c[1]!='\0w') c++;

	printf("%s\n",c);
	
}

int main(){
	char a[1000],b[1000];
	scanf("%s %s",a,b);

	int lA=0,lB=0;

	len(lA,a); len(lB,b);

	char c[2000];
	multStrings(a,b,c,lA,lB);
}