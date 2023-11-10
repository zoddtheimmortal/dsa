#include<iostream>
using namespace std;
int chairSwap(int arr[],int n);
int matchCheck(int arr[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
		int swaps=chairSwap(arr,n);
		cout<<swaps<<endl;
	}	
}

int chairSwap(int arr[],int n){
	int swaps=0,i=0,j=0;
	while(matchCheck(arr,n)!=-1){
		i=0;j=0;
		for(;i<n;i++){
			if(arr[i]==i+1) break;
		}
		j=i+1;
		for(;j<n;j++){
			if(arr[j]==j+1) break;
		}
		if(arr[i]!=j+1 && arr[j]!=i+1){
			swap(arr[i],arr[j]);
			swaps++;
		}

	}
	return swaps;

}

int matchCheck(int arr[],int n){
	for(int i=0;i<n;i++){
		if(arr[i]==i+1) return 0;
	}
	return -1;
}