/** 
 immortalzodd
 19.03.2024 23:03:33
 problemSolvingLog
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
    vi count(26,0);

    fr(i,0,n) count[str[i]-'A']++;
    ll ans=0;
    fr(i,0,26){
    	ans+=(count[i]>i);
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}