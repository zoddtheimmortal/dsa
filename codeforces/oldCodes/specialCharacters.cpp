/** 
 immortalzodd
 18.03.2024 11:19:39
 specialCharacters
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
    if(n%2!=0){
    	cout<<"NO\n";
    	return;
    }
    cout<<"YES"<<nL;
    fr(i,0,n/2){
    	if(i%2) cout<<"BB";
    	else cout<<"AA";
    }
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}