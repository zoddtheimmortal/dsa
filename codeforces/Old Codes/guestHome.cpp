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
    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    fr(i,0,n){
        int x,y; cin>>x>>y;
        arr[i]=make_pair(x,y);
    }
    ll ans=0;
    fr(i,0,n){
        fr(j,i+1,n){
            if(arr[i].first==arr[j].second) ans++;
            if(arr[i].second==arr[j].first) ans++;
        }
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}