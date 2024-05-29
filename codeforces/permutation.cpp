/** 
 immortalzodd
 25.05.2024 10:48:40
 permutation
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

void solve(){
    ll n; cin>>n;
    vi arr(n,0); for(int&x:arr) cin>>x;
    vi count(5001,0);
    for(int&x:arr) count[x-1]++;
    int ans=0;
	fr(i,0,n) ans+=(count[i]<1);
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