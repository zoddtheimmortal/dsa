#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll=long long;
using vi=vector<int>;

#define all(x) x.begin(),x.end()
#define v(x) vector<x>
#define pb push_back
#define fr(i,x,y) for(int i=x;i<y;i++)
#define rf(i,x,y) for(int i=y;i>=x;i--)
#define rep(it,arr) for(auto it:arr)
#define nL endl

bool checkSimple(vi arr,int n){
	while(1){
		sort(all(arr),greater<int>());
		if(arr[0]==0) return true;

		int pivot=arr[0];
		arr.erase(arr.begin());

		if(pivot>arr.size()) return false;

		fr(i,0,pivot){
			arr[i]-=1;
			if(arr[i]<0) return false;
		}
	}
}

void solve(){
	ll n; cin>>n;
	vi arr(n,0);
	fr(i,0,n) cin>>arr[i];
	cout<<(checkSimple(arr,n)?"YES":"NO")<<nL;
}

int main(){
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	} 
}