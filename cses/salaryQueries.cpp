/** 
 immortalzodd
 21.07.2024 11:52:06
 salaryQueries
**/
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>

using Tree =
    tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pll = pair<ll,ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,q;
vl arr;
const ll BIG=1e18;

void solve(){
	cin>>n>>q;
	arr.resize(n+1);
	Tree<pll> tree;
	fr(i,1,n+1){
		cin>>arr[i];
		tree.insert({arr[i],i});
	}
	while(q--){
		char c; ll x,y;
		cin>>c>>x>>y;
		if(c=='!'){
			tree.erase({arr[x],x});
			arr[x]=y;
			tree.insert({arr[x],x});
		}
		if(c=='?'){
			cout<<tree.order_of_key({y,BIG})-tree.order_of_key({x-1,BIG})<<nL;
		}
	}
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}