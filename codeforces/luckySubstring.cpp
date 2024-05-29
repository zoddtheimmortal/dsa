/** 
 immortalzodd
 25.05.2024 10:44:10
 luckySubstring
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
    string s; cin>>s;
    int four=0,seven=0;
    for(char&c:s){
    	if(c=='4') four++;
    	if(c=='7') seven++;
    }
    if(four==0&&seven==0) cout<<-1<<nL;
    else cout<<(four>=seven?4:7)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}