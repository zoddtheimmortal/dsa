/** 
 immortalzodd
 22.05.2024 00:40:13
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

ll n,x;
vi coins;
unsigned int MOD=1e9+7;

void solve(){
    cin>>n>>x;
    coins.assign(n,0); for(int&x:coins) cin>>x;
    vi dp(x+1,0);
    dp[0]=1;
    fr(i,0,n){
        fr(w,0,x+1){
            if(w-coins[i]>=0){
                dp[w]+=dp[w-coins[i]];
                dp[w]%=MOD;
            }
        }
    }

    cout<<dp[x]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}