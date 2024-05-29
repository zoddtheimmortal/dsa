/** 
 immortalzodd
 24.05.2024 23:43:46
 vacation
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

void solve(){
    cin>>n;
    int arr[n][3];
    fr(i,0,n){
    	fr(j,0,3) cin>>arr[i][j];
    }

    int dp[n+1][3]={0},p=0,q=0;
    fr(i,1,n+1){
    	fr(j,0,3){
    		p=(j+1)%3,q=(j+2)%3;
    		dp[i][j]=arr[i-1][j]+max(dp[i-1][p],dp[i-1][q]);
    	}
    }
    int ans=0;
    fr(j,0,3) ans=max(ans,dp[n][j]);
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