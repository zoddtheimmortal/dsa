/** 
 immortalzodd
 25.07.2024 14:35:37
 numberOfMinimumsOnASegment
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

template <class T> class MinSegmentTree {
  private:
	const T DEFAULT = {INT64_MAX,0};
	vector<T> segtree;
	int len;

  public:
	MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	T combine(T a, T b){
		if(a.first<b.first) return a;
		if(a.first>b.first) return b;
		return {a.first,a.second+b.second};
	}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = combine(segtree[ind],segtree[ind ^ 1]);
		}
	}

	T query(int start, int end) {
		T minpair = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { minpair = combine(minpair,segtree[start++]); }
			if (end % 2 == 1) { minpair = combine(minpair,segtree[--end]); }
		}
		return minpair;
	}
};
	
using pll = pair<ll,ll>;
ll n,q;

void solve(){
    cin>>n>>q;
    MinSegmentTree<pll> mst(n);
    fr(i,0,n){
    	ll x; cin>>x;
    	mst.set(i,{x,1});
    }

    fr(i,0,q){
    	ll t,x,y; cin>>t>>x>>y;
    	if(t==1) mst.set(x,{y,1});
    	else{
    		pll ans=mst.query(x,y);
    		cout<<ans.first<<" "<<ans.second<<nL;
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