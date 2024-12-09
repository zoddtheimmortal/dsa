/** 
 immortalzodd
 30.05.2024 11:26:27
 stairPeakOrNone
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
    ll a,b,c; cin>>a>>b>>c;
    if(a<b&&b<c) cout<<"STAIR"<<nL;
    else if(a<b&&b>c) cout<<"PEAK"<<nL;
    else cout<<"NONE"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}