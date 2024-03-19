/** 
 immortalzodd
 18.03.2024 19:05:28
 trickyTemplate
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
    string a,b,c; cin>>a>>b>>c;
    ll count=0;
    fr(i,0,n){
    	count+=((a[i]==c[i]||c[i]==b[i]));
    }
    cout<<(count==n?"NO":"YES")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}