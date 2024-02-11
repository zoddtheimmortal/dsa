#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int si=0,ei=n-1,ans=0;
	int nom=arr[si],psy=arr[ei];
	while(si<ei){
		if(nom==psy){
			ans=nom;
			si++; ei--;
			nom+=arr[si];
			psy+=arr[ei];
		}
		if(nom>psy){
			ei--;
			psy+=arr[ei];
		}
		if(psy>nom){
			si++;
			nom+=arr[si];
		}
	}

	printf("%d\n",ans);
}