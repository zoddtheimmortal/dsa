/** 
 immortalzodd
 26.05.2024 22:29:55
 petyaAndCountryside
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
	vi surfaces(n,0);
	int prev=0;
	fr(i,0,n){
		prev=arr[i];
		fr(j,i,n){
			if(arr[j]<=prev) surfaces[i]++;
			else break;
			prev=arr[j];
		}
		prev=arr[i];
		rf(j,0,i-1){
			if(arr[j]<=prev) surfaces[i]++;
			else break;
			prev=arr[j];
		}
	} 
	int ans=0;
	for(int&x:surfaces) ans=max(ans,x);
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