/** 
 immortalzodd
 16.07.2024 22:17:23
 testOfLove
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

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    string s; cin>>s;
    vi dp(n+2,-1);
    dp[0]=k;

    fr(i,1,n+2){
    	if(i!=n+1&&s[i-1]=='C') continue;
    	fr(j,1,m+1){
    		if(i-j>=0&&(i-j==0||s[i-j-1]=='L')){
    			dp[i]=max(dp[i],dp[i-j]);
    		}
    	}
    	if(i-2>=0&&s[i-2]=='W'){
    		dp[i]=max(dp[i],dp[i-1]-1);
    	}
    }
    cout<<(dp[n+1]>=0?"YES":"NO")<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}