/** 
 immortalzodd
 22.05.2024 20:38:30
 minCostClimbingStairs
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

int minCostClimbingStairs(vector<int>& cost){
	int n=cost.size();
	vi dp(n,INT_MAX);
	dp[0]=cost[0]; dp[1]=cost[1];
	fr(i,2,n){
		if(i-1>=0) dp[i]=min(dp[i],cost[i]+dp[i-1]);
		if(i-2>=0) dp[i]=min(dp[i],cost[i]+dp[i-2]);
	}
	return min(dp[n-1],dp[n-2]);
}

void solve(){
    ll n; cin>>n;
    vi cost(n,0); for(int&x:cost) cin>>x;
    cout<<minCostClimbingStairs(cost)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}