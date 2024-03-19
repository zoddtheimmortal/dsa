#include<stdio.h>
void removeX(int str[],int x);
int main(){
	int x,n;scanf("%d",&n,&x);
	int str[n];
	for(int i=0;i<n;i++){
		scanf("%d",&str[i]);
	}
	removeX(str,x);
	printf("%s\n",str);
}

void removeX(int str[],int x){
	if(str[0]=='\0') return;
	if(str[0]==x){
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		removeX(str,x);
	}
	else{
		removeX(str+1,x);
	}
}