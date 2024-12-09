/** 
 immortalzodd
 25.07.2024 12:25:40
 balancedPhoto
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
int arr[MXN],l[MXN],r[MXN];
Tree<int> lside,rside;

void solve(){
    cin>>n;
    fr(i,0,n) cin>>arr[i];

    fr(i,0,n){
    	l[i]=i-lside.order_of_key(arr[i]);
    	lside.insert(arr[i]);
    }

    rf(i,0,n-1){
    	r[i]=n-i-1-rside.order_of_key(arr[i]);
    	rside.insert(arr[i]);
    }

    ll ans=0;
    fr(i,0,n){
    	int top=max(r[i],l[i]),btm=min(l[i],r[i]);
    	ans+=(top>2*btm);
    }
    cout<<ans<<nL;
}

int main(){
	freopen("bphoto.in","r",stdin);
	freopen("bphoto.out","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}