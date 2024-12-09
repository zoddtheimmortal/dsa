/** 
 immortalzodd
 30.06.2024 13:00:07
 removingDigits
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

const ll BIG=1e18;

void solve(){
    ll n; cin>>n;
    vl dp(n+1,BIG);
    dp[0]=0;

    fr(i,1,n+1){
    	ll d=i;
    	while(d>0){
    		if(i-d%10>=0) dp[i]=min(dp[i],1+dp[i-d%10]);
    		d/=10;
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