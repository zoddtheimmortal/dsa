/** 
 immortalZodd
 25.01.2024 23:33:17
 stickLengths
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
    vl arr(n); for(auto &x:arr) cin>>x;
    sort(all(arr));
    ll cost=0,median=((n%2==0)?((arr[n/2]+arr[n/2-1])/2):(arr[n/2]));
    fr(i,0,n) cost+=abs(arr[i]-median);
    cout<<cost<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}