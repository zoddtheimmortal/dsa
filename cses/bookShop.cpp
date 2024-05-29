/** 
 immortalzodd
 21.05.2024 15:40:53
 bookShop
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
vi prices,pages;

void solve(){
    cin>>n>>x;
    prices.assign(n,0); pages.assign(n,0);
    for(int&x:prices) cin>>x;
    for(int&x:pages) cin>>x;

    vector<vi> dp(n+1,vi(x+1,0));
	fr(i,1,n+1){
		fr(j,0,x+1){
			int c=prices[i-1],p=pages[i-1];
			dp[i][j]=dp[i-1][j];
			dp[i][j]=(j-c>=0?max(dp[i][j],dp[i-1][j-c]+p):dp[i][j]);
		}
	}
	cout<<dp[n][x]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}