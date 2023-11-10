#include<bits/stdc++.h>
using namespace std;
int colorArray(int arr[],int n,int sum);
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,sum=0; cin>>n;
		int arr[n]={0}; 
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		cout<<(colorArray(arr,n,sum)?"YES":"NO")<<"\n";
	}
}

int colorArray(int arr[],int n,int sum){
	if(sum%2==0 && n>=2) return 1;
	return 0;
}
