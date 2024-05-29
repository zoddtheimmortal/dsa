/** 
 immortalzodd
 20.05.2024 22:15:37
 gridPaths
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

ll n;
vector<string> grid(1001);

void solve(){
    int MOD=1e9+7;
    cin>>n;
    fr(i,0,n) cin>>grid[i];
    vector<vi> dp(n,vi(n,0));
    dp[0][0]=1;
    fr(i,0,n){
    	fr(j,0,n){
    		if(grid[i][j]=='.'){
    			if(i>0) (dp[i][j]+=dp[i-1][j])%=MOD;
    			if(j>0) (dp[i][j]+=dp[i][j-1])%=MOD;
    		}
    		else dp[i][j]=0;
    	}
    }
    cout<<dp[n-1][n-1]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}