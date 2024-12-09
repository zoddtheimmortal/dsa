/** 
 immortalzodd
 15.07.2024 23:31:58
 missingCoinSum
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
vi arr;
const int MXN=2e5+5;

void solve(){
    cin>>n;
    arr.resize(n); for(int&x:arr) cin>>x;
    vi dp(10,0);
    dp[0]=1;
    ll ans=0;
    for(int&x:arr){
    	fr(i,1,10){
    		if(i-x>=0) dp[i]|=dp[i-x];
    	}
    }
    for(int&x:dp) cout<<x<<" ";
    cout<<nL;
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}