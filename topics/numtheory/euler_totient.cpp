/** 
 immortalzodd
 05.09.2024 11:24:08
 euler_totient
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

vi phi_1_to_n(int n){
	vi phi(n+1,1);

	fr(i,0,n+1) phi[i]=i;

	fr(i,2,n+1){
		if(phi[i]==i){
			for(ll j=i;j<n+1;j+=i){
				phi[j]-=phi[j]/i;
			}
		}
	}

	return phi;
}

void solve(){
    int n; cin>>n;
    vi phi = phi_1_to_n(n);

    fr(i,0,n+1){
    	cout<<i<<": "<<phi[i]<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}