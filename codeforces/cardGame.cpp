/** 
 immortalzodd
 07.08.2024 17:46:15
 cardGame
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
	int a,b,c,d; cin>>a>>b>>c>>d;

    int ans=0;
    if(a>c&&b>d) ans+=2;
    if(a>d&&b>c) ans+=2;

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