#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int makeEqual(char a[],char b[]){
	int l1=0,l2=0,len=0;

	while(a[l1]!='\0') l1++;
	while(b[l2]!='\0') l2++;

	char x[100000],y[100000];
	len=max(l1,l2);
	int i=0,j=0;
	while(i<len-l1) x[i++]='0';
	while(j<len-l2) y[j++]='0';

	int m=0,n=0;
	while(i<len) x[i++]=a[m++];
	while(j<len) y[j++]=b[n++];

	i=0,j=0;
	while(i<len){
		a[i]=x[i];
		i++;
	}

	while(j<len){
		b[j]=y[j];
		j++;
	}

	return len;

}

int addStrings(char a[],char b[],char c[]){
	int len=makeEqual(a,b);
	int i=0,sum=0,carry=0;

	while(len>0){
		sum=((a[len-1]-'0')+(b[len-1]-'0')+carry)%10;
	
		carry=((a[len-1]-'0')+(b[len-1]-'0')+carry)/10;
		c[i++]=sum+'0';
		len--;
	}

	if(carry>0) c[i++]=carry+'0';

	int j=0;
	for(;j<i/2;j++){
		char t=c[j];
		c[j]=c[i-j-1];
		c[i-j-1]=t;
	}

	c[i++]='\0';
	return i;
}

void karatsubaMult(char x[],char y[],char z[]){
	int len=makeEqual(x,y);

	if(len==0) return;
	if(len==1){
		z[0]=((((x[0]-'0')*(y[0]-'0')))/10)+'0';
		z[1]=((((x[0]-'0')*(y[0]-'0')))%10)+'0';
		return;
	}

	char a[100000],b[100000],c[100000],d[100000];
	int i=0,j=0;
	while(i<len/2) a[i++]=x[i];
	while(j<len/2) c[j++]=y[j];
	a[i++]='\0',c[j++]='\0';

	i=0,j=0;
	while(i<len) b[i++]=x[len/2+i];
	while(j<len) d[j++]=y[len/2+j];

	b[i++]='\0',d[j++]='\0';
	char p[100000],q[100000],r[100000],s[100000];

	karatsubaMult(a,c,p);
	karatsubaMult(b,d,q);
	karatsubaMult(a,d,r);
	karatsubaMult(b,c,s);

	printf("%s %s %s %s\n",p,q,r,s);

	char p1[100000],p2[100000],p3[100000];

	int len1=addStrings(r,s,p1);
	i=0,j=0;
	while(i<len/2){
		p1[i+len1]='0';
		i++;
	}

	int len2=0;
	while(p[len2]!='\0') len2++;

	while(j<len){
		p[j+len2]='0';
		j++;
	}

	int len3=addStrings(p,p1,p2);
	int len4=addStrings(p2,q,p3);
	i=0;
	while(i<len4){
		z[i++]=p3[i];
	}

	printf("%s %s %s %s\n",p,p1,p2,p3);

	z[i++]='\0';
	return;

}

int main(){
	char a[100000],b[100000],c[200000];
	scanf("%s %s",a,b);
	karatsubaMult(a,b,c);
	printf("%s\n",c);
}