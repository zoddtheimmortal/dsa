/** 
 immortalzodd
 25.05.2024 17:52:34
 roadsideTreesSimplified
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
    int n; cin>>n;
    vi arr(n,0); for(int&x:arr) cin>>x;
    int ans=arr[0]+1,pos=arr[0];
    fr(i,1,n){
    	ans+=(2+abs(pos-arr[i]));
    	pos=arr[i];
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