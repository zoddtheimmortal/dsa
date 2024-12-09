/** 
 immortalzodd
 18.07.2024 17:19:27
 listRemovals
**/
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

template <class T>
using Tree = 
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll n; cin>>n;
    Tree<int> ist;
    vi arr(n);

    fr(i,0,n){
    	ist.insert(i);
    	cin>>arr[i];
    }

    fr(i,0,n){
    	int x; cin>>x;
    	x--;
    	int pos=*ist.find_by_order(x);
    	ist.erase(pos);
    	cout<<arr[pos]<<" ";
    }
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