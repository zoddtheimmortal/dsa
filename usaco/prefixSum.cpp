/**
 immortalZodd
 15.01.2024 18:00:07
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

vl psum(vl &arr){
	vl psum(arr.size()+1,0);
	fr(i,0,arr.size()) psum[i+1]=psum[i]+arr[i];
	return psum;
}

void solve(){
    ll n,q; cin>>n>>q;
    vl arr(n,0); for(auto& x:arr) cin>>x;
    vl sum=psum(arr);

    while(q--){
    	ll l,r; cin>>l>>r;
    	cout<<sum[r]-sum[l]<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}