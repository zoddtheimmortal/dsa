#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void solve(){
    ll n,k,x; cin>>n>>k>>x;
    ll frontSum=(k*(k+1)/2),backSum=(n*(n+1)/2)-((k-n-1)*(k-n)/2);
    // ll count=0;
    // for(ll i=n;count<k;i--){
    //     backSum+=i;
    //     count++;
    // }
    bool ans=true;
    if(frontSum>x || backSum<x) ans=false;
    cout<<(ans?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}