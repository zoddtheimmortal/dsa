/** 
 immortalzodd
 18.03.2024 14:20:43
 shuffleParty
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

#define MAXN 1e9

vector<int> prime;
bool is_composite[(long long)MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i <= n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 2; i * j <= n; ++j)
			is_composite[i * j] = true;
	}
}


void solve(){
	ll n; cin>>n;
	sieve(n);
	ll ans=1;
	for(int i=n;i>=0;i--){
		if(!is_composite[i]){ans=i;break;}
	}
	cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  	
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}