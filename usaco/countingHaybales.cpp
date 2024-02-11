/** 
 immortalZodd
 27.01.2024 00:50:24
 countingHaybales
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
	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);
    ll n,k; cin>>n>>k;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    sort(all(arr));
    while(k--){
    	ll fp,sp; cin>>fp>>sp;
    	auto si=upper_bound(all(arr),fp-1);
    	auto ei=upper_bound(all(arr),sp);
    	cout<<ei-si<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}