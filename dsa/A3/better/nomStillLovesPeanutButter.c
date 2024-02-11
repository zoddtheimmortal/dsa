#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int si=-1,ei=n,ans=0,nom=0,psy=0;
	while(si<ei){
		if(nom==psy){
			ans=nom;
			si++; ei--;
			nom+=arr[si];
			psy+=arr[ei];
		}
		else if(nom>psy){
			ei--;
			psy+=arr[ei];
		}
		else{
			si++;
			nom+=arr[si];
		}
	}

	printf("%d\n",ans);

	free(arr);
}