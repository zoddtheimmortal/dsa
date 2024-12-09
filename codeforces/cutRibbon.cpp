/** 
 immortalzodd
 14.07.2024 23:33:45
 cutRibbon
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
    ll n; cin>>n;
    vi arr(3); for(int&x:arr) cin>>x;
    vi dp(4001,INT_MIN);
    for(int&x:arr) dp[x]=1;
    fr(i,1,n+1){
    	for(int&x:arr){
    		if(i-x>=0) dp[i]=max(dp[i],dp[i-x]+dp[x]);
    	}
    }
    cout<<dp[n]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}