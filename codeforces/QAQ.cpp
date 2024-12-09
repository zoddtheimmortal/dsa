/** 
 immortalzodd
 26.06.2024 09:23:36
 QAQ
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

const string b = "QAQ";

void solve(){
    string a; cin>>a;
    int n=a.size(),m=b.size();
    vector<vi> dp(n+1,vi(m+1,0));
    fr(i,0,n+1) dp[i][0]=1;
    fr(i,1,n+1){
    	fr(j,1,m+1){
    		dp[i][j]+=dp[i-1][j];
    		if(a[i-1]==b[j-1]) dp[i][j]+=dp[i-1][j-1];
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