/** 
 immortalzodd
 20.02.2024 18:57:29
 makeItWhite
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
    string str; cin>>str;
    ll prefix=0,suffix=0,i=0;
    while(str[i++]=='W') prefix++;
    i=n-1;
    while(str[i--]=='W') suffix++;
    cout<<n-(prefix+suffix)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}