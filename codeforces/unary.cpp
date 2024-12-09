/** 
 immortalzodd
 02.06.2024 00:40:46
 unary
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

unsigned int MOD=1000003;

void solve(){
    string s; cin>>s;
    int map[256],k=15;
    string code="][,.-+<>";
    for(char&c:code) map[c]=k--;
    int ans=0,n=s.size();
	for(char&c:s){
		ans=(ans<<4)+map[c];
		ans%=MOD;
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