/** 
 immortalzodd
 24.05.2024 15:23:38
 removalGame
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
vi arr;

void solve(){
    cin>>n;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    vector<vi> dp(n,vi(n,0));
    fr(i,0,n) dp[i][i]=arr[i];
    
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}