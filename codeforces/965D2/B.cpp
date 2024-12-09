/** 
 immortalzodd
 10.08.2024 20:21:32
 B
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
	vi arr(n); for(int&x:arr) cin>>x;

	vi temp=arr;
	for(int&x:temp){
		if(x!=1) x--;
		else x=n;
	}

	for(int&x:temp) cout<<x<<" ";

	cout<<nL;    
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}