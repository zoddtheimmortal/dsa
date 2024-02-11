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
    ll n,m,k; cin>>n>>m>>k;
    vi arr(n),brr(m);
    fr(i,0,n) cin>>arr[i];
    fr(i,0,m) cin>>brr[i];

    sort(all(arr)); sort(all(brr));

    ll i=0,j=0,ans=0;
    for(;i<n;i++){
    	while(j<m && brr[j]<arr[i]-k) j++;
    	if(j<m && brr[j]<=arr[i]+k) j++,ans++;
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