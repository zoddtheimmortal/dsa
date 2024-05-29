#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int value[MAX_N],weight[MAX_N],visited[MAX_N];
int n,W; 

int findMax(){
	int m=0;
	double ans=0;
	for(int i=0;i<n;i++){
		double temp=value[i]/weight[i];
		if(temp>ans && !visited[i]){
			ans=temp; m=i;
		}
		if(temp==ans && !visited[i]){
			if(W>=weight[i]&&weight[i]<=weight[m]){
				ans=temp; m=i;
			}
		}
	}
	visited[m]=1;
	return m;
}

int main(){
	scanf("%d %d",&n,&W);
	for(int i=0;i<n;i++){
		scanf("%d %d",&weight[i],&value[i]);
		visited[i]=0;
	}

	int i=0;
	double ans=0;
	while(W>0){
		i=findMax();
		if(W-weight[i]>=0){
			ans+=value[i];
			W-=weight[i];
		}
		else break;
	}
	ans=ans+((W*1.0/weight[i])*value[i]);
	printf("%.1lf\n",ans);
}