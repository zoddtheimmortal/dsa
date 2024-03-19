#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,min=INT_MAX; cin>>n;
		std::vector<int> arr(n); cin>>arr[0];
		for(int i=1;i<n;i++){
			cin>>arr[i];
			if(arr[i]-arr[i-1]<min) min=arr[i]-arr[i-1];
		}
		cout<<((min<0)?0:(min/2+1))<<endl;
	}	
}