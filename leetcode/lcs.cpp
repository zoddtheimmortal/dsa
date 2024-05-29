/** 
 immortalzodd
 21.05.2024 20:57:45
 lcs
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
    string a,b; cin>>a>>b;
    int n=a.size(),m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    fr(i,1,n+1){
    	fr(j,1,m+1){
    		if(a[i-1]==b[j-1]){
    			dp[i][j]=1+dp[i-1][j-1];
    		}
    		else{
    			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    		}
    	}
    }

    cout<<dp[n][m]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}