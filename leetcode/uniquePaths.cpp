/** 
 immortalzodd
 23.05.2024 15:09:29
 uniquePaths
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

int uniquePaths(int n,int m){
	vector<vi> dp(n,vi(m,0));
	fr(i,0,n) dp[i][0]=1;
	fr(j,0,m) dp[0][j]=1;

	fr(i,1,n){
		fr(j,1,m){
			dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
		}
	}
	return dp[n-1][m-1];
}

void solve(){
	int n,m; cin>>n>>m;
    cout<<uniquePaths(n,m)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}