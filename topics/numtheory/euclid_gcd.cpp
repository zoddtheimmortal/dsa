/** 
 immortalzodd
 05.09.2024 10:31:54
 euclid_gcd
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

ll gcd(ll a,ll b){
	return (b==0?a:gcd(b,a%b));
}

void solve(){
    ll n,m; cin>>n>>m;

    cout<<gcd(n,m)<<nL;
    cout<<std::gcd(n,m)<<nL;
    cout<<__gcd(n,m)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}