/** 
 immortalzodd
 05.08.2024 14:26:08
 orderCheck
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
    ll n; cin>>n;
    vi arr(n); for(int&x:arr) cin>>x;

    vi srt(all(arr));
    sort(all(srt));

    ll ans=0;
    fr(i,0,n){
    	ans+=(arr[i]!=srt[i]);
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