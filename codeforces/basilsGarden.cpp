/** 
 immortalzodd
 14.07.2024 12:39:14
 basilsGarden
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

ll n;
vi arr;

void solve(){
	cin>>n;
	arr.resize(n); for(int&x:arr) cin>>x;

	ll ans=arr[n-1];
	for(int i=n-2;i>=0;i--){
		ans=max<ll>(1+ans,arr[i]);
	}
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}