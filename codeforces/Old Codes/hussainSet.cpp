#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	std::vector<int> arr(n); for(int i=0;i<n;i++) cin>>arr[i];	
	std::vector<int> q(m); for(int i=0;i<m;i++) cin>>q[i];
	int k=0;
	for(int i=0;i<q[m-1];i++){
		std::vector<int>::iterator max=max_element(arr.begin(), arr.end());
		if(i+1==q[k]){ cout<<*(max)<<endl; k++;}
		*max=(*max)/2;
		if(*(max)<=0) arr.erase(max);
	}
}