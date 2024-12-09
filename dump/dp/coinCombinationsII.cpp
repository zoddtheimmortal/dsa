/** 
 immortalzodd
 30.06.2024 12:08:23
 coinCombinationsII
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

ll n,x;
vi coins;
const int MOD=1e9+7;

void solve(){
    cin>>n>>x;
    coins.assign(n,0); for(int&x:coins) cin>>x;
    vi dp(x+1,0);
    dp[0]=1;

    for(int&c:coins){
    	fr(i,1,x+1){
    		if(i-c>=0) dp[i]=(dp[i-c]+dp[i])%MOD;
    	}
    }
    cout<<dp[x]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}