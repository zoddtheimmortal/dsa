/** 
 immortalzodd
 14.07.2024 11:57:14
 yetAnotherCoinProblem
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

int coins[5]={1,3,6,10,15};
const int BIG=1e9;

void solve(){
    ll n; cin>>n;
    vi dp(n+1,BIG);
    dp[0]=0;
    fr(i,1,n+1){
    	for(int&c:coins){
    		if(i-c>=0) dp[i]=min(dp[i],1+dp[i-c]);
    	}
    }
    cout<<dp[n]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}