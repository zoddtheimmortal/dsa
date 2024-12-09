/** 
 immortalzodd
 07.08.2024 23:47:02
 clockConversion
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
    int hr,min;
    char c; cin>>hr>>c>>min;
    int h=(hr+12)%12;
    if(hr==0||hr==12) h=12;
    if(h/10==0) cout<<0;
    cout<<h<<":";
    if(min/10==0) cout<<0;
    cout<<min;
    if(hr<12) cout<<" AM"<<nL;
    else cout<<" PM"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}