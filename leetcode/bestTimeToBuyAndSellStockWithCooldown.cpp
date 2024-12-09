/** 
 immortalzodd
 20.06.2024 00:34:12
 bestTimeToBuyAndSellStockWithCooldown
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

const int B = 0, S = 1, C = 2;
const int MIN = -1000;
using vi = vector<int>;
int maxProfit(vector<int>& cost) {
    int n = cost.size();
    vector<vi> dp(n, vi(3, MIN));
    dp[0][S] = 0;
    dp[0][B] = -cost[0];
    dp[0][C] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i - 1; j++) {
            dp[i][B] = max(dp[i][B], -cost[i] + max(dp[j][S],dp[j][C]));
        }
        dp[i][B]=max(dp[i][B],-cost[i]+dp[i-1][C]);
        for (int j = 0; j < i; j++) {
            dp[i][S] = max(dp[i][S], cost[i] + dp[j][B]);
            dp[i][C] =
            max(dp[i][C], max(dp[j][C], dp[j][S]));
        }
    }
    fr(i,0,n){
        cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<nL;
    }
    return max(max(0,dp[n-1][C]), max(dp[n - 1][S], dp[n - 1][B]));
}

void solve(){
    ll n; cin>>n;
    vi arr(n); for(int&x:arr) cin>>x;
    cout<<maxProfit(arr)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}