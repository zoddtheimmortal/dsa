/** 
 immortalzodd
 04.08.2024 19:02:55
 autocorrectPrototype
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
    ll n,q; cin>>n>>q;
    vector<string> arr(n); vector<string> qry(q);
    for(string&s:arr) cin>>s;
    for(string&s:qry) cin>>s;

    vector<string> sorted(arr.begin(),arr.end());
	for(string&s:sorted) sort(all(s));


	for(string&q:qry){
		vector<string> ans;
		sort(all(q));
		for(int i=0;i<sorted.size();i++){
			if(sorted[i]==q) cout<<arr[i]<<" ";
		}
		cout<<nL;
	}
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}