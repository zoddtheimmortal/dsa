/** 
 immortalzodd
 23.07.2024 22:32:44
 increasingFrequency
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

int dp[50005];

void solve(){
    ll n,k; cin>>n>>k;

    ll cnt=0,mx=0;
    fr(i,0,n){
    	ll c; cin>>c;
    	if(c==k) cnt++;
    	else dp[c]=1+max<ll>(dp[c],cnt);
    	mx=max(mx,dp[c]-cnt);
    }
    cout<<mx+cnt<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}