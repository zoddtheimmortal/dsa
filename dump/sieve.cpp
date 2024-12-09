/** 
 immortalzodd
 05.08.2024 15:31:26
 sieve
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

const int MXN=1e9;
bool composite[MXN];
vi prime;

void sieve(int n){
	fill(composite,composite+n,false);
	fr(i,2,n){
		if(!composite[i]) prime.push_back(i);
		for(int j=2;i*j<n;j++){
			composite[i*j]=true;
		}
	}
}

void solve(){
	int n; cin>>n;
   sieve(n);
   for(int&x:prime) cout<<x<<" ";
   cout<<nL; 
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}