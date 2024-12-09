/** 
 immortalzodd
 31.05.2024 19:50:26
 deque
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
vl arr;

void solve(){
    cin>>n;
    arr.assign(n,0); for(ll&x:arr) cin>>x;
    vector<vl> dp(n,vl(n,0));
    fr(i,0,n) dp[i][i]=arr[i];

    rf(i,0,n-1){
        fr(j,i+1,n){
            dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}