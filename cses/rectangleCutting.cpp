/** 
 immortalzodd
 22.05.2024 22:19:49
 rectangleCutting
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

void solve(){
    ll x,y; cin>>x>>y;
    vector<vi> dp(x,vi(y,INT_MAX));
    fr(i,0,x) dp[i][0]=i;
    fr(j,0,y) dp[0][j]=j;

    fr(i,1,x){
    	fr(j,1,y){
    		if(i==j){
    			dp[i][j]=0; continue;
    		}
    		fr(k,1,i) dp[i][j]=min(dp[i][j],1+dp[i-k][j]+dp[k-1][j]);
    		fr(k,1,j) dp[i][j]=min(dp[i][j],1+dp[i][j-k]+dp[i][k-1]);
    	}
    }

    cout<<dp[x-1][y-1]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}