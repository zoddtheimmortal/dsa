#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		std::vector<int> arr(n); for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr.begin(), arr.end());
		int temp=1,ans=1;
		for(int i=1;i<n;i++){
			if(arr[i]-arr[i-1]>k) temp=1;
			else{
				temp++;
			}
			ans=max(ans,temp);
		}
		cout<<n-ans<<endl;
	}
}