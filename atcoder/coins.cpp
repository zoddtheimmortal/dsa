/** 
 immortalzodd
 26.05.2024 23:42:23
 coins
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
vector<double> prob;

void solve(){
    cin>>n;
    prob.assign(n,0); for(double&x:prob) cin>>x;
    vector<double> dp(n,1);
    fr(i,0,n){
    	fr(k,0,i) dp[i]*=prob[i];
    	fr(k,i,n) dp[i]*=1-prob[i];
    }
    for(auto&x:dp) cout<<x<<" ";
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}