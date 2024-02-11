/**
 immortalZodd
 20.01.2024 17:21:54
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
    vl psum(n+1,0);
    fr(i,0,n){
    	ll x; cin>>x;
    	psum[i+1]=psum[i]+x;
    }

    ll maxSum=psum[1],minSum=psum[0];
    fr(i,0,n){
    	maxSum=max(maxSum,psum[i+1]-minSum);
    	minSum=min(minSum,psum[i+1]);
    }

    cout<<maxSum<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}