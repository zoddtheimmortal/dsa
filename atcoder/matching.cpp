/** 
 immortalzodd
 10.06.2024 14:43:38
 matching
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

const int MAX_N=21;
const unsigned int MOD=1e9+7;

int n;
int dp[1<<MAX_N],arr[MAX_N][MAX_N];

void solve(){
    cin>>n;
    fr(i,0,n){
    	fr(j,0,n) cin>>arr[i][j];
    }

    dp[0]=1;
    fr(s,0,1<<n){
    	int pair_num=__builtin_popcount(s);
    	fr(x,0,n){
    		if((s&(1<<x))||!arr[pair_num][x]) continue;
    		dp[s|(1<<x)]+=dp[s];
    		dp[s|(1<<x)]%=MOD;
    	}
    }

    cout<<dp[(1<<n)-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}