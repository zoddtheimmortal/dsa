/** 
 immortalzodd
 04.08.2024 08:59:03
 fun
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
    ll n,x; cin>>n>>x;
    ll ans=0;

    fr(a,1,min(n,x)+1){
    	for(int b=1;a*b<=n&&a+b<=x;b++){
    		ll c=min((n-(a*b))/(a+b),x-(a+b));
    		ans+=c;
    	}
    }
    cout<<ans<<nL;	
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}