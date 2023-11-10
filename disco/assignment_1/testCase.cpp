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
    cout<<50<<" "<<(50*(51))/2<<nL;
    for(int i=1;i<51;i++){
        cout<<i<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    freopen("output.txt","w",stdout);

    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}