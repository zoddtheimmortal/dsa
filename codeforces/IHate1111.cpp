/** 
 immortalzodd
 14.07.2024 23:41:10
 IHate1111
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
	fr(i,0,20){
		if(n%11==0){
			cout<<"YES"<<nL;
			return;
		}
		n-=111;
		if(n<0) break;
	}
	cout<<"NO"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}