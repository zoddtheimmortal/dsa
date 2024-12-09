/** 
 immortalzodd
 25.06.2024 16:05:31
 equalize2
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

ll n;
string a,b;

void solve(){
    cin>>n>>a>>b;
    vi dp(n+1,INT_MAX);
    dp[0]=0; dp[1]=(a[0]!=b[0]);
    fr(i,2,n+1){
    	if(a[i-1]==b[i-1]) dp[i]=dp[i-1];
    	else{
    		dp[i]=min(dp[i],1+dp[i-1]);
    		string t=""; t+=a[i-1]; t+=a[i-2];
    		if(t=="01"||t=="10"){
    			dp[i]=min(dp[i],1+dp[i-2]);
    		}
    	}
    }
    cout<<dp[n]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}