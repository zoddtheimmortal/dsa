/** 
 immortalzodd
 18.03.2024 14:34:30
 tooMinTooMax
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
    vi arr(n,0); for(auto&x:arr) cin>>x;
    sort(all(arr));

    int a=arr[n-1],b=arr[0],c=arr[n-2],d=arr[1];
    ll ans=abs(a-b)+abs(a-d)+abs(b-c)+abs(c-d);
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