/** 
 immortalzodd
 07.08.2024 17:43:52
 a+bAgain
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
	string s=to_string(n);
	int ans=0;
	for(char&c:s) ans+=c-'0';
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