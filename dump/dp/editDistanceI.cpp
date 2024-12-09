/** 
 immortalzodd
 13.07.2024 09:47:25
 editDistanceI
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

const int BIG=1e9;

void solve(){
    string a,b; cin>>a>>b;
    int n=a.size(),m=b.size();
    vector<vi> dp(n+1,vi(m+1,BIG));
    fr(i,0,n+1) dp[i][0]=i;
    fr(j,0,m+1) dp[0][j]=j;

    fr(i,1,n+1){
    	fr(j,1,m+1){
    		dp[i][j]=min(1+dp[i-1][j],1+dp[i][j-1]);
    		dp[i][j]=min(dp[i][j],(a[i-1]!=b[j-1])+dp[i-1][j-1]);
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