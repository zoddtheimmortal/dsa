/**
 immortalZodd
 21.01.2024 00:26:53
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
    ll n,q; cin>>n>>q;
    vector<vi> arr(n,vi(n,0));
    fr(i,0,n){
        fr(j,0,n){
            char x; cin>>x;
            if(x=='*') arr[i][j]=1;
        }
    }

    vector<vi> psum(n+1,vi(n+1,0));

    fr(i,1,n+1){
        fr(j,1,n+1){
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+arr[i-1][j-1];
        }
    }

    while(q--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans=psum[c][d]-psum[a-1][d]-psum[c][b-1]+psum[a-1][b-1];
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