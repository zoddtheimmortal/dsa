#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		std::vector<int> arr(n);
		for(int i=0;i<n;i++){
			int x; cin>>x;
			x%=k;
			x=(x==0)?(k):(x);
			arr[i]=x;
		}
		std::vector<int> order(n);
		for(int i=0;i<n;i++) order[i]=i;
		sort(order.begin(), order.end(),[&](int i,int j){
			return arr[i]>arr[j];
		});
		for(int i=0;i<n;i++) cout<<order[i]+1<<" ";
		cout<<endl;
	}	
}
