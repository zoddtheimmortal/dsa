/** 
 immortalzodd
 23.05.2024 18:40:26
 countingTowers
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

#define N 1000001

unsigned int MOD=1e9+7;
ll dp[N][2]={0};

void PRE(){
	dp[1][0]=1,dp[1][1]=1;
	fr(i,2,N){
    	dp[i][0]=0,dp[i][1]=0;
    	dp[i][0]+=(2*dp[i-1][0]+dp[i-1][1]);
    	dp[i][0]%=MOD;
    	dp[i][1]+=(4*dp[i-1][1]+dp[i-1][0]);
    	dp[i][1]%=MOD;
    }
}

void solve(){
    ll n; cin>>n;
    cout<<(dp[n][0]+dp[n][1])%MOD<<nL;
}

int main(){
    fast_io;
    PRE();
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}