/** 
 immortalzodd
 26.07.2024 22:10:24
 independentSet
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

ll n;
const int MXN=1e5+5;
const int MOD=1e9+7;
ll dp[MXN][2]={0};
vi arr[MXN];

void dfs(int x,int p){
	dp[x][0]=dp[x][1]=1;
	for(int&y:arr[x]){
		if(y!=p){
			dfs(y,x);
			dp[x][0]*=(dp[y][1]+dp[y][0]);
			dp[x][1]*=dp[y][0];
			dp[x][0]%=MOD; dp[x][1]%=MOD;
		}
	}
}

void solve(){
    cin>>n;
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1])%MOD<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}