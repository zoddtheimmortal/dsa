/** 
 immortalzodd
 17.07.2024 23:10:20
 mortalKombatTower
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

const int BIG=1e9;

void solve(){
    ll n; cin>>n;
    vi arr(n); for(int&x:arr) cin>>x;
    vector<vi> dp(n+1,vi(2,BIG));
    dp[0][1]=0; dp[1][0]=arr[0];

    fr(i,2,n+1){
    	dp[i][0]=min(dp[i][0],dp[i-1][1]+arr[i-1]);
    	dp[i][0]=min(dp[i][0],dp[i-2][1]+arr[i-1]+arr[i-2]);
    	dp[i][1]=min(dp[i][1],min(dp[i-1][0],dp[i-2][0]));
    }
    cout<<min(dp[n][0],dp[n][1])<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}