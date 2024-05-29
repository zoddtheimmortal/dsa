/** 
 immortalzodd
 28.03.2024 17:40:23
 medianOfAnArray
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
    vi arr(n); for(auto &x:arr) cin>>x;
    sort(all(arr));
    ll med=arr[(n-1)/2],ans=0;
    for(int i=((n-1)/2);i<n;i++) ans+=(med==arr[i]);
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