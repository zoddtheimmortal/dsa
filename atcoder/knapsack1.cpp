/** 
 immortalzodd
 25.05.2024 22:19:11
 knapsack1
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

void solve(){
    ll n,w; cin>>n>>w;
    vi val(n,0),wt(n,0);
    fr(i,0,n) cin>>wt[i]>>val[i];
    vector<vl> dp(n+1,vl(w+1));
    fr(i,1,n+1){
    	fr(j,0,w+1){
    		if(j-wt[i-1]>=0) dp[i][j]=max<ll>(
    			val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
    		else dp[i][j]=dp[i-1][j];
    	}
    }
    cout<<dp[n][w]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}