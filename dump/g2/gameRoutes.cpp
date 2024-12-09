/** 
 immortalzodd
 17.08.2024 09:31:01
 gameRoutes
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
const int MOD=1e9+7;

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    }

    vi indeg(n,0);
    fr(i,0,n){
    	for(int&x:arr[i]) indeg[x]++;
    }

	queue<int> qs;
	fr(i,0,n) if(indeg[i]==0) qs.push(i);

	vl dp(n,0);
	dp[0]=1;

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		for(int&u:arr[v]){
			if(--indeg[u]==0) qs.push(u);
			dp[u]+=dp[v];
			dp[u]%=MOD;
		}
	}

	cout<<dp[n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}