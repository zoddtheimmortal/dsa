/**
 immortalZodd
 18.01.2024 23:11:25
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

void solve(){
    ll n; cin>>n;
    map<ll,ll> mp;
    ll psum=0,ans=0;
    mp[0]=1;
    fr(i,0,n){
    	ll x; cin>>x;
    	psum+=x;

    	mp[abs(psum)%n]++;
    }

    map<ll,ll>::iterator it=mp.begin();
    while(it!=mp.end()){
    	ll x=it->second;
    	ans+=(x*(x-1))/2;
    	it++;
    }

    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}