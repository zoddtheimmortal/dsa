/** 
 immortalzodd
 26.06.2024 09:52:50
 fillingShapes
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

void solve(){
    cin>>n;
    vl dp(n+1,0);
    dp[0]=1;
    fr(i,2,n+1){
    	if(i%2==0) dp[i]=2*dp[i-2];
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