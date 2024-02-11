#include<stdio.h>
#include<string.h>

int main(){
	char a[1000],b[1000];
	char c[2000];
	scanf("%s %s",a,b);
	int cin=0,i=0,m=0,n=0;
	for(;b[m]!='\0';m++);
	for(;a[n]!='\0';n++);
	for(;m-1>=0;m--){
		int x=a[n-1]-'0',y=b[m-1]-'0';
		int sum=(x+y+cin)%10;
		cin=(x+y+cin)/10;
		c[i++]=sum+'0';
		n--;
	}
	for(;n-1>=0;n--){
		c[i++]=(((a[n-1]-'0')+cin)%10)+'0';
		cin=((a[n-1]-'0')+cin)/10;
	}
	if(cin!=0){
		c[i++]=cin+'0';
	}
	for(int j=i-1;j>=0;j--){
		printf("%c",c[j]);
	}
}