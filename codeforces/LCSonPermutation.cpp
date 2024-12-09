/** 
 immortalzodd
 18.07.2024 10:10:03
 LCSonPermutation
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
    ll n; cin>>n;
    vi a(n),b(n);
    for(int&x:a) cin>>x;
    for(int&x:b) cin>>x;

    vector<vi> dp(n+1,vi(n+1,0));
	
	ll ans=0;
	fr(i,1,n+1){
		fr(j,1,n+1){
			if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			ans=max<ll>(ans,dp[i][j]);
		}
	}

	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}