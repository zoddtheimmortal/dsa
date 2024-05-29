/** 
 immortalzodd
 21.05.2024 22:48:25
 frog1
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

ll n;
vi arr;

void solve(){
    cin>>n;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    vi dp(n,INT_MAX);
    dp[0]=0;
    fr(i,1,n){
    	if(i-1>=0) dp[i]=min(dp[i],abs(arr[i]-arr[i-1])+dp[i-1]);
    	if(i-2>=0) dp[i]=min(dp[i],abs(arr[i]-arr[i-2])+dp[i-2]);
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