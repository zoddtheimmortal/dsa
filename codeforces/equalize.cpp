/** 
 immortalzodd
 28.03.2024 11:53:54
 equalize
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

    arr.resize(unique(all(arr))-arr.begin());

    ll ei=0,ans=0;
    fr(i,0,arr.size()){
    	while(arr[i]-arr[ei]>=n) ei++;
    	ans=max(ans,i-ei+1);
    }
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