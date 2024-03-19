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
    int r,c; cin>>r>>c;
    vector<pair<int,int>> straw;
    fr(i,0,r){
        fr(j,0,c){
            char s; cin>>s;
            if(s=='S') straw.pb(make_pair(i,j));
        }
    }
    ll ans=0,j=0;
    vi row;
    fr(i,0,r){
        bool found=false;
        fr(j,0,straw.size()){
            if(i==straw[j].first){
                found=true;
                break;
            }
        }
        if(found==false){
            ans+=c;
            row.pb(i);
        }
    }
    j=0;
    fr(i,0,c){
        bool found=false;
        fr(j,0,straw.size()){
            if(i==straw[j].second){
                found=true;
                break;
            }
        }
        if(found==false){
            ans+=(r-row.size());
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