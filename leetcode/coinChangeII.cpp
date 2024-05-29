/** 
 immortalzodd
 23.05.2024 14:55:03
 coinChangeII
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

unsigned int MOD=1e9+7;

int change(int amount,vector<int>&coins){
	vector<int> dp(amount+1,0);
	int n=coins.size();
	for(int i=0;i<n;i++){
		for(int j=1;j<=amount;j++){
			if(j-coins[i]>=0){
				dp[j]+=dp[j-coins[i]];
				dp[j]%=MOD;
			}
		}
	}
	return dp[amount];
}

void solve(){
    ll n,x; cin>>n>>x;
    vi coins(n,0); for(int&x:coins) cin>>x;
    cout<<change(x,coins)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}