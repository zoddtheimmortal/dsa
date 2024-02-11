/** 
 immortalZodd
 26.01.2024 10:42:17
 towers
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

void solve(){
    ll n; cin>>n;
    multiset<ll> ms;
    ms.insert(INT_MAX);
    while(n--){
        ll box; cin>>box;
        auto mx=(ms.rbegin());
        if(box>*mx){
            ms.insert(box);
        }else{
            auto up=ms.upper_bound(box);
            if(up!=ms.end()) ms.erase(up);
            ms.insert(box);
        }
    }
    cout<<ms.size()<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}