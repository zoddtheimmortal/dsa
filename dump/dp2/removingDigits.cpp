/** 
 immortalzodd
 19.08.2024 15:38:30
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
    	string k=to_string(i);
    	for(char&c:k){
    		if(i-(c-'0')>=0) dp[i]=min(dp[i],1+dp[i-(c-'0')]);
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