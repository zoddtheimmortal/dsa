/** 
 immortalzodd
 23.02.2024 18:58:07
 plusMinusSplit
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
    string s; cin>>s;
    ll plus=0,minus=0;
    fr(i,0,n){
    	plus+=(s[i]=='+');
    	minus+=(s[i]=='-');
    }
    cout<<abs(plus-minus)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}