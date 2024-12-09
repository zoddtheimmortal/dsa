/** 
 immortalzodd
 31.05.2024 23:37:12
 verifyPassword
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
    string sorted=s; sort(all(sorted));
    bool dig=false,srt=false;
    fr(i,1,n) dig|=(s[i-1]-'a'<=26&&s[i-1]-'a'>=0&&
    	s[i]-'0'<=9&&s[i]-'0'>=0);
    fr(i,0,n) srt|=(s[i]!=sorted[i]);
    cout<<(dig||srt?"NO":"YES")<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}