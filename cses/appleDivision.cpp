/** 
 immortalZodd
 07.02.2024 23:03:59
 appleDivision
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
    vi arr(n,0); for(auto &x:arr) cin>>x;

    ll ans=INT_MAX;
    for(int mask=0;mask<(1<<n);mask++){
    	ll l=0,r=0;
    	fr(i,0,n){
    		if(mask&(1<<i)) l+=arr[i];
    		else r+=arr[i];
    	}
    	ans=min(ans,abs(l-r));
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