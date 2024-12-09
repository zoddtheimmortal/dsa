/** 
 immortalzodd
 17.07.2024 12:04:51
 8888888
**/
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

using mint=modint998244353;

void solve(){
	ll n,x; cin>>n>>x;
	mint r=1;

	cin>>n;
	x=n;
	while(x){
		x/=10;
		r*=mint(10);
	}

	mint ans=mint(n)*(r.pow(n)-mint(1))*((r-mint(1)).inv());
	cout<<ans.val()<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}