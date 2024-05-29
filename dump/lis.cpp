/** 
 immortalzodd
 21.05.2024 15:27:46
 lis
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

void solve(){
    ll n; cin>>n;
    vi arr(n); for(int&x:arr) cin>>x;
    vi dp(n,1);
    dp[0]=1;

    fr(i,0,n){
    	fr(k,0,i){
    		if(arr[k]<arr[i]){
    			dp[i]=max(dp[i],1+dp[k]);
    		}
    	}
    }
    int ans=0;
    for(int&x:dp) ans=max(ans,x);
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