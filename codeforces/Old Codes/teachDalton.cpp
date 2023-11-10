#include<iostream>
using namespace std;
int swapMaster(int arr[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
		int ans=swapMaster(arr,n);
		cout<<ans<<endl;
	}	
}

int swapMaster(int arr[],int n){
	int inp=0;
	for(int i=0;i<n;i++){
		if(arr[i]==i+1) inp++;
	}
	if(inp%2==0) return inp/2;
	else{
		return ((inp/2)+1);
	}
}