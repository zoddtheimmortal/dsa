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
    int n,m; cin>>n>>m;
    ll one=0,minus=0;
    vi arr(n);
    fr(i,0,n){
        cin>>arr[i];
        if(arr[i]>0) one++;
        else if(arr[i]<0) minus++;
    }
    while(m--){
        bool ans=true;
        int l,r; cin>>l>>r;
        if((r-l+1)%2!=0) ans=false;
        else if(one<(r-l+1)/2 || minus<(r-l+1)/2) ans=false;
        cout<<ans<<nL;
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