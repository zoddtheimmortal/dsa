/** 
 immortalzodd
 24.07.2024 16:02:21
 rangeXorSegment
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

template <class T> class XorSegmentTree {
  private:
	const T DEFAULT = 0;
	vector<T> segtree;
	int len;

  public:
	XorSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = segtree[ind] ^ segtree[ind ^ 1];
		}
	}

	T range_sum(int start, int end) {
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum ^= segtree[start++]; }
			if (end % 2 == 1) { sum ^= segtree[--end]; }
		}
		return sum;
	}
};

ll n,q;

void solve(){
    cin>>n>>q;
    XorSegmentTree<ll> xst(n);
    fr(i,0,n){
    	int x; cin>>x;
    	xst.set(i,x);
    }

    fr(i,0,q){
    	int a,b; cin>>a>>b;
    	cout<<xst.range_sum(a-1,b)<<nL;
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