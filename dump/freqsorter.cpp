/** 
 immortalzodd
 27.07.2024 20:28:05
 freqsorter
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
    string s; cin>>s;
    int m; cin>>m;

    map<char,int> mp;
    for(int&c:s) mp[c]++;

    vi arr;
    for(auto[x,val]:mp) arr.push_back(val);
    sort(arr.begin(),arr.end());

	ll ans=0;
	int n=arr.size(),si=0,ei=n-1;

	while(si<=ei){
		if(arr[si]<arr[ei]-arr[si+1]+m){
			ans+=arr[si];
		}
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