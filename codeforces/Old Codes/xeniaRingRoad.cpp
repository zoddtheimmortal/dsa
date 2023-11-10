#include<iostream>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
	int arr[m]; for(int i=0;i<m;i++) cin>>arr[i];
	long long int time=arr[0]-1,flag=arr[0];
	for(int i=0;i<m;i++){
		if(flag<=arr[i]){
			 time+=(arr[i]-flag);
		}
		else if(flag>arr[i]){
			 time+=(n-flag+arr[i]);
		}
		flag=arr[i];
	}
	cout<<time<<'\n';
}