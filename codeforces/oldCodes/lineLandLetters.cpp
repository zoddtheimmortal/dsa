#include<iostream>
using namespace std;
#define min(a,b) (a>b)?(b):(a)
#define max(a,b) (a>b)?(a):(b)
void maxDistance(int arr[],int n);
int main(){
	int n; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	maxDistance(arr,n);	
}

void maxDistance(int arr[],int n){
	for(int i=0;i<n;i++){
		if(i==0){
			cout<<arr[i+1]-arr[i]<<" "<<arr[n-1]-arr[i]<<endl;
		}
		else if(i==n-1){
			cout<<arr[i]-arr[i-1]<<" "<<arr[i]-arr[0]<<endl;
		}
		else{
			int a=min((arr[i]-arr[i-1]),(arr[i+1]-arr[i]));
			int b=max((arr[n-1]-arr[i]),(arr[i]-arr[0]));
			cout<<a<<" "<<b<<endl;
		}
	}
}