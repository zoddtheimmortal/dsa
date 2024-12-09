/** 
 immortalzodd
 23.07.2024 23:41:54
 phidias
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

const int MXN=605;
int n,m,p;
int h[MXN],w[MXN];
const int BIG=1e9;

void solve(){
    cin>>n>>m>>p;
    vector<vi> dp(n+1,vi(m+1,BIG));
    fr(i,0,p){
    	cin>>h[i]>>w[i];
    }

    fr(i,1,n+1){
    	fr(j,1,m+1) dp[i][j]=i*j;
    }

    fr(i,0,p) dp[h[i]][w[i]]=0;

    fr(i,1,n+1){
    	fr(j,1,m+1){
    		fr(q,1,i){
    			dp[i][j]=min(dp[i][j],dp[i-q][j]+dp[q][j]);
    		}
    		fr(p,1,j){
    			dp[i][j]=min(dp[i][j],dp[i][j-p]+dp[i][p]);
    		}
    	}
    }

    cout<<dp[n][m]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}