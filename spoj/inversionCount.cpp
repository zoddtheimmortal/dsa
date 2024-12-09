/** 
 immortalzodd
 21.07.2024 11:44:19
 inversionCount
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
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll n; cin>>n;
    Tree<int> tree;

    ll inv_count=0;
    fr(i,0,n){
    	ll x; cin>>x;
    	inv_count+=i-tree.order_of_key(x);
    	tree.insert(x);
    }
    cout<<inv_count<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}