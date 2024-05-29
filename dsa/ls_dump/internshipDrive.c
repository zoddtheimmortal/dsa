#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

char arr[MAX_N];
int stack[MAX_N],top=-1,mp[255]={0};

int main(){
	scanf("%s",arr);
	mp['{']='}',mp['(']=')',mp['[']=']';
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]=='{'||arr[i]=='('||arr[i]=='['){
			stack[++top]=arr[i];
		}
		else if(i==0){
			top++; break;
		}
		else{
			int x=stack[top];
			if(mp[x]==arr[i]) top--;
			else break;
		}
	}

	printf("%s\n",(top<0?"YES":"NO"));
}