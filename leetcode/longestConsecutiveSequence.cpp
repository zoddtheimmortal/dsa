/** 
 immortalzodd
 29.05.2024 22:59:05
 longestConsecutiveSequence
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

int longestConsecutive(vector<int>& arr) {
	int n=arr.size();
	sort(arr.begin(),arr.end());
	int si=0,ei=1,ans=1;
	while(si<n&&ei<n){
		while(ei<n&&arr[ei]-arr[ei-1]<=1) ei++;
		ans=max(ans,ei-si);
		cout<<si<<" "<<ei<<nL;
		si=ei;
		ei++;
	}
	return ans;
}

void solve(){
	int n; cin>>n;
	vi arr(n,0); for(int&x:arr) cin>>x;
	cout<<longestConsecutive(arr)<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}