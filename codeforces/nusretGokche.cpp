/**
 immortalZodd
 21.01.2024 18:26:43
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
    ll n,m; cin>>n>>m;
    vl arr(n,0); for(auto &x:arr) cin>>x;

    fr(i,1,n){
    	arr[i]=max(arr[i],arr[i-1]-m);
    }

    for(int i=n-2;i>=0;i--){
    	arr[i]=max(arr[i],arr[i+1]-m);
    }

    for(auto &x:arr) cout<<x<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}