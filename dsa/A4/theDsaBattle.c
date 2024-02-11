#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,a,b; scanf("%d %d %d",&n,&a,&b);
	int kira_left=a,nom_left=b;
	int grps=b,grp_size=n/b,k_rep=n/(b+1),n_rep=1;
	char* ans=(char*) malloc(sizeof(char)*n);

	int k=0;

	for(int i=0;i<grps;i++){
		for(int j=0;j<k_rep;j++) ans[k++]='K';
		for(int j=0;j<n_rep;j++) ans[k++]='O';
		if(kira_left<0) break;
		nom_left-=n_rep;
	}
	for(int i=0;i<kira_left;i++) ans[k++]='K';

	if(kira_left>k_rep){
		for(int i=0;i<n/2;i++){
			char t=ans[i];
			ans[i]=ans[n-i-1];
			ans[n-i-1]=t;
		}
	}
	printf("%s\n",ans);
}