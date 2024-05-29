#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int stack[MAX_N],mp[256],top=-1;

int main(){
	char arr[MAX_N];
	scanf("%s",arr);

	mp['{']='}',mp['(']=')',mp['[']=']';
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]=='{'||arr[i]=='['||arr[i]=='(') stack[++top]=arr[i];
		else if(i==0){
			++top; break;
		}
		else{
			if(mp[stack[top]]!=arr[i]) break;
			top--;
		}
	}

	printf("%s\n",(top<0?"YES":"NO"));
}