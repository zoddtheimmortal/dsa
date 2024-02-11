/** 
 immortalZodd
 25.01.2024 19:37:34
 trafficLights
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
	ll n,q; cin>>n>>q;

	set<ll> lights; 
	lights.insert(0); lights.insert(n);

	multiset<ll> dist;
	dist.insert(n);

	while(q--){
		ll k; cin>>k;
		auto mx=lights.upper_bound(k);
		auto mn=mx;
		mn--;
		dist.erase(dist.find(*mx-*mn));
		dist.insert(k-*mn);
		dist.insert(*mx-k);

		ll ans=*(dist.rbegin());
		cout<<ans<<" ";
		lights.insert(k);
	}
	cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}