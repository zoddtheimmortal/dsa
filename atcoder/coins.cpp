/** 
 immortalzodd
 31.05.2024 15:54:39
 coins
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<long double>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

#define P 12

void solve(){
    ll n; cin>>n;
    vd p(n,0); for(auto&x:p) cin>>x;
    vector<vd> dp(n+1,vd(n+1,0));
    fr(i,0,n+1) dp[i][0]=1;
    fr(i,1,n+1){
    	fr(j,1,n+1){
    		dp[i][j]=dp[i-1][j-1]*(p[i-1])+dp[i-1][j]*(1-p[i-1]);
    	}
    }
    cout<<setprecision(P)<<dp[n][n/2+1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}