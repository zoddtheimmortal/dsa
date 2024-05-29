/** 
 immortalzodd
 25.05.2024 11:44:56
 vasyasCalender
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
    ll c,n; cin>>c>>n;
    vi arr(n,0); for(int&x:arr) cin>>x;
    ll ans=0;
    fr(i,0,n-1) ans+=abs(c-arr[i]);
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