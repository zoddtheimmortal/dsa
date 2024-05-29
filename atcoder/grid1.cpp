/** 
 immortalzodd
 26.05.2024 23:27:00
 grid1
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

ll h,w;
vector<string> grid;
unsigned int MOD=1e9+7;

void solve(){
    cin>>h>>w;
    grid.resize(h); for(string&s:grid) cin>>s;
    vector<vl> dp(h+1,vl(w+1,0LL));
    dp[1][1]=1;
    fr(i,1,h+1){
    	fr(j,1,w+1){
    		if(grid[i-1][j-1]=='.'){
    			dp[i][j]+=dp[i-1][j]+dp[i][j-1];
    			dp[i][j]%=MOD;
    		}
    	}
    }
    cout<<dp[h][w]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}