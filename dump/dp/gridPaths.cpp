/** 
 immortalzodd
 30.06.2024 21:14:13
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n;
vector<string> grid;
const int MOD=1e9+7;

void solve(){
	cin>>n;
	grid.resize(n); for(string&s:grid) cin>>s;
	vector<vi> dp(n+1,vi(n+1,0));
	dp[1][1]=(grid[0][0]=='.'); 
	fr(i,1,n+1){
		fr(j,1,n+1){
			if(grid[i-1][j-1]=='.'){
				dp[i][j]+=dp[i-1][j];
				dp[i][j]+=dp[i][j-1];
				dp[i][j]%=MOD;
			}
		}
	}
	cout<<dp[n][n]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}