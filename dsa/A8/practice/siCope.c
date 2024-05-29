#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int stack[MAX_N],top=-1,minEle=0;
int queue[MAX_N],tail=-1,head=0,sum=0;

/*
11 
1 3 
1 7 
1 6 
1 4 
3 
2 
1 1
3 
2 
2
3
*/

void push(int x){
	if(top<0){
		stack[++top]=x;
		minEle=x;
	}
	else if(x<minEle){
		stack[++top]=2*x-minEle;
		minEle=x;
	}
	else stack[++top]=x;

	queue[++tail]=x;
	sum+=x;
}

void pop(){
	int t=stack[top];
	top--;

	if(t<minEle) minEle=2*minEle-t;

	int b=queue[head++];
	sum-=b;
}

int main(){
	int n; scanf("%d",&n);

	while(n--){
		int x; scanf("%d",&x);
		if(x==1){
			int y; scanf("%d",&y);
			push(y);
		}
		else if(x==2){
			pop();
		}
		else{
			printf("%d %d\n",minEle,(sum/(tail-head+1)));
		}
	}
}