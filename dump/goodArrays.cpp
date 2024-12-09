/** 
 immortalzodd
 19.07.2024 17:23:13
 goodArrays
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

ll n,x;
vi arr;
ll ans;

ll exactX(ll k){
	unordered_map<ll,ll> freq;
	ll si=0,ei=0,ans=0;
	while(ei<n){
		freq[arr[ei]]++;
		while(freq.size()>k){
			freq[arr[si]]--;
			if(freq[arr[si]]<=2) freq.erase(arr[si]);
			si++;
		}
		ans+=ei-si+1;
		ei++;
	}
	return ans;
}

void solve(){
    cin>>n>>x;
    arr.resize(n); for(int&x:arr) cin>>x;
    cout<<exactX(x)-exactX(x-1)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}