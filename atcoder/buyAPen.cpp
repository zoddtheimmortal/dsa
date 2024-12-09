/** 
 immortalzodd
 15.07.2024 15:37:46
 buyAPen
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
    ll r,g,b; cin>>r>>g>>b;
    string exc; cin>>exc;
    if(exc=="Red") cout<<min(g,b)<<nL;
    if(exc=="Blue") cout<<min(r,g)<<nL;
    if(exc=="Green") cout<<min(r,b)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}