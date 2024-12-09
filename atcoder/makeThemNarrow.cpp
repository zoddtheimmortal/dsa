/** 
 immortalzodd
 16.07.2024 23:12:54
 makeThemNarrow
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

void solve(){
    ll n,k; cin>>n>>k;
    vi arr(n); for(int&x:arr) cin>>x;
    sort(all(arr));
    k=n-k;
    ll si=0,ei=k-1,ans=INT64_MAX;
    while(ei<n){
    	ans=min<ll>(ans,arr[ei]-arr[si]);
    	si++;
    	ei++;
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}