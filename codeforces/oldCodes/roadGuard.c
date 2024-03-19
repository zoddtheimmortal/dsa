#include<stdio.h>
int main(){
	int n,h; scanf("%d %d",&n,&h);
	int len=0;
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		if(a>h) len+=2;
		else len++;
	}
	printf("%d",len);
}