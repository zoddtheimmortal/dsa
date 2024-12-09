/** 
 immortalzodd
 30.06.2024 11:47:27
 minimizingCoins
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
const ll BIG=1e18;

void solve(){
    cin>>n>>x;
    coins.assign(n,0); for(int&x:coins) cin>>x;
    vl dp(x+1,BIG);
    dp[0]=0;

    fr(i,1,x+1){
    	for(int&c:coins){
    		if(i-c>=0) dp[i]=min(dp[i],1+dp[i-c]);
    	}
    }
    cout<<(dp[x]<BIG?dp[x]:-1)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}