/** 
 immortalzodd
 27.06.2024 18:13:52
 exponetiation
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

const int MOD=1e9+7;

ll calcpow(ll a,ll b){
	if(b==0) return 1;
	if(b==1) return a%MOD;
	ll half=calcpow(a,b/2);
	if(b%2==0) return (half*half)%MOD;
	return (((half*half)%MOD)*a)%MOD;
}

void solve(){
    ll a,b; cin>>a>>b;
    cout<<calcpow(a,b)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}