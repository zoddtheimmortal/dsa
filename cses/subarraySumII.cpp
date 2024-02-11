/**
 immortalZodd
 15.01.2024 23:22:39
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
    ll n,k; cin>>n>>k;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    ll p=0,ans=0;

    map<ll,ll> sum;
    sum[0]=1;

    fr(i,0,n){
        //calculating prefix sums
        p+=arr[i];
        //at any p, we get new subarrays to exclude to get needed s.arr
        ans+=sum[p-k];
        sum[p]++;
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