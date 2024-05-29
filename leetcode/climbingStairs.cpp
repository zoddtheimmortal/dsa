/** 
 immortalzodd
 22.05.2024 20:34:40
 climbingStairs
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

int climbStairs(int n){
	vi dp(n+1,0);
	dp[0]=1; dp[1]=1;
	fr(i,2,n+1){
		if(i-1>=0) dp[i]+=dp[i-1];
		if(i-2>=0) dp[i]+=dp[i-2];
	}
	return dp[n];
}

void solve(){
    int n; cin>>n;
    cout<<climbStairs(n)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}