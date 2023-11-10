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
    vi arr;
    ll sum=0;
    fr(i,0,n){
    	ll x; cin>>x;
    	arr.pb(x);
    	sort(all(arr));
    	fr(j,0,n){
    		if(arr[j]==x) break;
    		sum+=arr[j];
    	}
    }
    cout<<sum<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}