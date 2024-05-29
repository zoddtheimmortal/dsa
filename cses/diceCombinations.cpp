/** 
 immortalzodd
 20.05.2024 20:22:41
 diceCombinations
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
#define MOD ((unsigned int)1e9+7)

ll n;

ll combos(ll n){
	vl dp(n+1,0);
	dp[0]=1;dp[1]=1;
	fr(i,2,n+1){
		fr(x,1,7){
			dp[i]+=((i-x<0)?0:dp[i-x]);
			dp[i]%=MOD;
		}
	}
	return dp[n];
}

void solve(){
	cin>>n;
	ll ans=combos(n);
	cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}