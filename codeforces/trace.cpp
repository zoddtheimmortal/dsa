/** 
 immortalzodd
 25.05.2024 11:10:39
 trace
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

#define PI 3.1415926536

void solve(){
    int n; cin>>n;
	vi radii(n,0); for(int&x:radii) cin>>x;
	sort(all(radii),greater<int>());
	ll sign=1,area=0;
	for(int&r:radii){
		area+=(sign*r*r);
		sign*=-1;
	}
	cout<<setprecision(12)<<PI*area<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}