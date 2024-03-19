#include<stdio.h>
void removeX(char str[],char x);
int main(){
	char str[200],x; scanf("%s %c",&str,&x);
	removeX(str,x);
	printf("%s\n",str);
}

void removeX(char str[],char x){
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