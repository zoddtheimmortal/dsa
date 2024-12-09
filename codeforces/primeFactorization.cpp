/** 
 immortalzodd
 25.08.2024 14:13:36
 primeFactorization
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
    vi ans;
    for(ll i=2;i*i<=n;i++){
    	while(n%i==0){
    		ans.push_back(i);
    		n/=i;
    	}
    }
    if(n>1) ans.push_back(n);

    cout<<ans[0];
    fr(i,1,ans.size()){
    	cout<<"*"<<ans[i];
    }
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