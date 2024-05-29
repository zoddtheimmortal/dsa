/** 
 immortalzodd
 26.05.2024 18:38:29
 phoneNumbers
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
    ll n; cin>>n;
    string s; cin>>s;
    int last=2;
    if(n%2!=0) last++;
    fr(i,0,n-last){
    	cout<<s[i]<<s[i+1]<<'-';
    	i++;
    }
    fr(i,n-last,n) cout<<s[i];
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}