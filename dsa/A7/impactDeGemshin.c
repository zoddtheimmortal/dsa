#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int N=26;

void heapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,large=i;
	if(left<n&&arr[left]>arr[large]) large=left;
	if(right<n&&arr[right]>arr[large]) large=right;

	if(large!=i){
		int temp=arr[large];
		arr[large]=arr[i];
		arr[i]=temp;
		heapify(arr,n,large);
	}
}

void sort(int* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
	for(int i=n-1;i>=0;i--){
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,i,0);
	}
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	char* arr=(char*) malloc(sizeof(char)*n);
	for(int i=0;i<n;i++){
		char x; scanf("%c",&x);
		if(x==' '||x=='\n'){
			i--; continue;
		}
		arr[i]=x;
	}

	int mp[26]={0};
	for(int i=0;i<n;i++) mp[arr[i]-'a']++;

	sort(mp,26);
	
	int i=0,c=0,ans=0;
	while(i<N&&mp[i]==0) i++;
	while(i<N&&c<=k){
		int x=((c+mp[i])<=k?mp[i]:k-c);
		ans+=(x*x);
		c+=x;
		i++;
	}
	printf("%d\n",ans);
}