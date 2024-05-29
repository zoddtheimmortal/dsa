/** 
 immortalzodd
 25.05.2024 18:06:57
 cowsAndPokerGame
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
    int n; cin>>n;
    string s; cin>>s;
    vi map(26,0);
    for(char&c:s) map[c-'A']++;
    int ans=0;
	for(char&c:s){
		if(c=='A'||c=='I'){
			map[c-'A']--;
			ans+=(map['I'-'A']<=0);
			map[c-'A']++;
		}
	}
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