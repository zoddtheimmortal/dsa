/** 
 immortalzodd
 25.07.2024 11:02:10
 promotionCounting
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

const int MXN=1e5+5;
ll n;
int ans[MXN],a[MXN];
vi arr[MXN];
Tree<int> d[MXN];

void dfs(int x,int p=0){
	for(int&y:arr[x]){
		if(y==p) continue;
		dfs(y,x);

		if(d[x].size()<d[y].size()) d[x].swap(d[y]);
		for(int i:d[y]) d[x].insert(i);
	}
	
	ans[x]=d[x].size()-d[x].order_of_key(a[x]);
	d[x].insert(a[x]);
}

void solve(){
    cin>>n;
    fr(i,1,n+1) cin>>a[i];
    fr(i,2,n+1){
    	ll j; cin>>j;
    	arr[i].push_back(j);
    	arr[j].push_back(i);
    }

    dfs(1);

    fr(i,1,n+1) cout<<ans[i]<<nL;
}

int main(){
	freopen("promote.in","r",stdin);
	freopen("promote.out","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}