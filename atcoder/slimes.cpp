/** 
 immortalzodd
 31.05.2024 20:56:25
 slimes
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

ll n;

void solve(){
	cin>>n;
	priority_queue<ll> pq;
	fr(i,0,n){
		int x; cin>>x; pq.push(-x);
	}
	ll ans=0;
	while(!pq.empty()){
		ll x=-pq.top();
		pq.pop();
		if(pq.empty()){
			break;
		}
		ll y=-pq.top();
		pq.pop();
		ans+=(x+y);
		pq.push(-x-y);
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