/** 
 immortalzodd
 20.02.2024 19:06:15
 followingTheString
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
    vi arr(n,0); for(auto &x:arr) cin>>x;
    string str(n,'a');

    vi alp(26,0);
    fr(i,0,n){
    	if(arr[i]<alp[str[i]-'a']){
            while(arr[i]<alp[str[i]-'a']){
                str[i]++;
            }
    	}
    	alp[str[i]-'a']++;
    }

    cout<<str<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}