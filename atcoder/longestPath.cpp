/** 
 immortalzodd
 26.05.2024 12:31:39
 longestPath
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

ll n,m;
vector<vi> arr;
vi dp;

int dfs(int x){
	if(dp[x]) return dp[x];
	for(int&y:arr[x]){
		dp[y]=dfs(y);
		dp[x]=max(dp[x],1+dp[y]);
	}
	return dp[x];
}

void solve(){
	cin>>n>>m;
	arr.resize(n);
	fr(i,0,m){
		ll f,s; cin>>f>>s;
		arr[--f].push_back(--s);
	}
	dp.assign(n,0);
	fr(i,0,n) dfs(i);
	int ans=0;
	for(int&x:dp) ans=max(ans,x);
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}