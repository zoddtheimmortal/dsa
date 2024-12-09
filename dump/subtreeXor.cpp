/** 
 immortalzodd
 24.07.2024 17:45:26
 subtreeXor
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

template <class T> class SumSegmentTree {
  private:
	const T DEFAULT = 0;
	vector<T> segtree;
	int len;

  public:
	SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
		}
	}

	T range_sum(int start, int end) {
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum += segtree[start++]; }
			if (end % 2 == 1) { sum += segtree[--end]; }
		}
		return sum;
	}
};


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

	T range_xor(int start, int end) {
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum ^= segtree[start++]; }
			if (end % 2 == 1) { sum ^= segtree[--end]; }
		}
		return sum;
	}
};

const int MXN=2e5+5;
ll n;
vi arr[MXN];
int st[MXN],en[MXN],vals[MXN];
int timer=0;

void dfs(int x,int p){
	st[x]=timer++;
	for(int&y:arr[x]){
		if(y!=p) dfs(y,x);
	}
	en[x]=timer;
}

void solve(){
    cin>>n;
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    ll total=0;
    fr(i,1,n+1){
    	cin>>vals[i];
    	total+=vals[i];
    }

    dfs(1,0);

    XorSegmentTree<ll> xst(n);
    SumSegmentTree<ll> sst(n);

    fr(i,1,n+1){
    	xst.set(st[i],vals[i]);
    	sst.set(st[i],vals[i]);
    }

    ll ans=0,node=-1;
    fr(i,1,n+1){
    	ll stree_xor=xst.range_xor(st[i],en[i]);
    	ll stree_sum=sst.range_sum(st[i],en[i]);

    	if(stree_xor+total-stree_sum>ans){
    		ans=stree_xor+total-stree_sum;
    		node=i;
    	}
    }
    cout<<node<<" "<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}