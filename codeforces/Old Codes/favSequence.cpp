#include<iostream>
using namespace std;
void restoreSequence(int arr[],int n);
#define K (i+j)
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
		restoreSequence(arr,n);
		cout<<endl;
	}	
}

void restoreSequence(int arr[],int n){
	int i=0,j=0;
	for(;K<n;){
		if((K+1)%2!=0){
			cout<<arr[i]<<" ";
			i++;
		}
		else if(((K+1)%2)==0){
			cout<<arr[n-j-1]<<" ";
			j++;
		}
	}
}