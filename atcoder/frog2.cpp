/** 
 immortalzodd
 21.05.2024 22:58:27
 frog2
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

ll n,k;
vi stones;

void solve(){
    cin>>n>>k;
    stones.assign(n,0); for(int&x:stones) cin>>x;
    vi dp(n,INT_MAX); dp[0]=0;
    fr(i,1,n){
    	fr(p,1,k+1){
    		if(i-p>=0) dp[i]=min(dp[i],dp[i-p]+abs(stones[i]-stones[i-p]));
    	}
    }
    cout<<dp[n-1]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}