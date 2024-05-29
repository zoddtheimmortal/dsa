#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_N (unsigned int)1e6

int main(){
	char arr[MAX_N],stack[MAX_N],mp[256];
	mp['{']='}',mp['(']=')',mp['[']=']';
	scanf("%s",arr);

	int top=-1;
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]=='{'||arr[i]=='['||arr[i]=='('){
			stack[++top]=arr[i];
		}
		else if(i==0){
			++top;
			break;
		}
		else{
			char stop=stack[top];
			if(mp[stop]!=arr[i]) break;
			top--;
		}
	}
	printf("%s\n",(top==-1)?"YES":"NO");
}