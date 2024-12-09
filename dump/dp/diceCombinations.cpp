/** 
 immortalzodd
 30.06.2024 11:43:51
 diceCombinations
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

const int MOD=1e9+7;

void solve(){
	ll x; cin>>x;
	vi dp(x+1,0);
	dp[0]=1;
	fr(i,1,x+1){
		fr(j,1,7){
			if(i-j>=0) dp[i]=(dp[i]+dp[i-j])%MOD;
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