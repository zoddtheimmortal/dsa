/** 
 immortalzodd
 27.07.2024 21:26:21
 wildcardMatching
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

int dp[2005][2005]={0};
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp[0][0]=1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j-1]&&(p[i-1]==s[i-1]||p[i-1]=='?');
                }
            }
        }

        fr(i,0,n+1){
        	fr(j,0,m+1) cout<<dp[i][j]<<" ";
        	cout<<nL;
        }
        return dp[n][m];
    }

void solve(){
    string s,p; cin>>s>>p;
    cout<<isMatch(s,p)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}