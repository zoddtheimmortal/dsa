#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d",&n);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int si=0,ei=n-1,nom=arr[0],psy=arr[n-1],ans=0;
	while(si<ei){
		if(nom==psy){
			ans=nom;
			nom+=arr[++si];
			psy+=arr[--ei];
		}
		else if(nom<psy){
			nom+=arr[++si];
		}
		else{
			psy+=arr[--ei];
		}
	}

	printf("%d\n",ans);
}