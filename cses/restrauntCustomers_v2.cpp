/** 
 immortalzodd
 25.05.2024 10:56:47
 restrauntCustomers_v2
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
    vi in(n,0),out(n,0);
    ll top=0;
    fr(i,0,n){
    	cin>>in[i]>>out[i];
    	top=max<ll>(top,max(in[i],out[i]));
    }
    vl count(top+1,0);
    fr(i,0,n){
    	count[in[i]]=1;
    	count[out[i]]=-1;
    }
    fr(i,1,top+1) count[i]+=count[i-1];
    ll ans=0;
    for(auto&x:count) ans=max<ll>(ans,x);
    cout<<ans<<nL;
}

int main(){
	freopen("rest.in","r",stdin);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}