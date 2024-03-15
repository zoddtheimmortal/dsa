/** 
 immortalzodd
 26.02.2024 20:33:43
 casegen
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
	freopen("median.in","w",stdout);
    ll q; cin>>q;
    cout<<q<<nL;
    while(q--){
    	if(q%3==1) cout<<2<<nL;
    	else cout<<1<<" "<<q<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}