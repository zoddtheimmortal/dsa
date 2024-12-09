/** 
 immortalzodd
 21.07.2024 17:10:32
 subtreeQueries
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

ll n,q;
vector<vi> arr;
vi s,e,vals;
int timer=0;

void dfs(int x,int p){
	s[x]=timer++;
	for(int&y:arr[x]){
		if(y!=p) dfs(y,x);
	}
	e[x]=timer;
}

void solve(){
    cin>>n>>q;
    arr.resize(n); vals.resize(n);
    for(int&x:vals) cin>>x;

    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    s.assign(n,0); e.assign(n,0);
    dfs(0,-1);

    SumSegmentTree<ll> tree(n);

    fr(i,0,n) tree.set(s[i],vals[i]);

    fr(i,0,q){
    	ll t; cin>>t;
    	if(t==1){
    		int x,y; cin>>x>>y;
    		tree.set(s[--x],y);
    	}
    	if(t==2){
    		int node; cin>>node;
    		--node;
    		cout<<tree.range_sum(s[node],e[node])<<nL;
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