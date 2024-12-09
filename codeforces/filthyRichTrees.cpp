/** 
 immortalzodd
 24.07.2024 11:04:02
 filthyRichTrees
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using ld = long double;

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

const int MXN=3e5+5;
ll n,q;
vi arr[MXN];
int st[MXN],en[MXN];
ld vals[MXN];
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
    fr(i,1,n+1) vals[i]=log(1.0);

    dfs(0,0);

    SumSegmentTree<ld> pst(n);
    fr(i,1,n+1) pst.set(st[i],vals[i]);

    cin>>q;
    fr(i,0,q){
    	int t,x,y; cin>>t>>x>>y;
    	if(t==1){
    		ll newval=log(y);
    		pst.set(st[x],y);
    	}
    	if(t==2){
    		ld l1=pst.range_sum(st[x],en[x]);
    		ld l2=pst.range_sum(st[y],en[y]);
    		ld ans=l1-l2;
    		ans=max<ld>(min<ld>(ans,log(1e9)),log(1e-9));
    		cout<<(ld)exp(ans)<<nL;
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