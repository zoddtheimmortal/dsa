/** 
 immortalzodd
 31.05.2024 22:01:42
 twoSetsII
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
unsigned int MOD=1e9+7;

void solve(){
	cin>>n;
	if(n%4==1||n%4==2){
		cout<<0<<nL;
		return;
	}
	ll sum=n*(n+1)/4;
	vector<vi> dp(n,vi(sum+1,0));
	dp[0][0]=1;

	fr(i,1,n){
		fr(j,0,sum+1){
			dp[i][j]+=dp[i-1][j];
			if(j-i>=0) dp[i][j]+=dp[i-1][j-i];
			dp[i][j]%=MOD;
		}
	}
	cout<<dp[n-1][sum]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}