/** 
 immortalzodd
 25.07.2024 12:20:21
 haircut
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>

using Tree =
    tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n;
const int MOD=1e9;
Tree<pair<int,int>> ord;

void solve(){
    cin>>n;
    vi ans(n);
    fr(i,0,n){
    	int x; cin>>x;
    	ans[i]=ord.order_of_key({x,MOD});
    	ord.insert({x,i});
    }
    for(int&x:ans) cout<<x<<" ";
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}