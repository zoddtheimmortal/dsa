/** 
 immortalzodd
 22.07.2024 23:42:29
 companyQueriesIIET
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

ll n,q;
const int MXN=2e5+5;
int tin[MXN],tour[MXN];
vi arr[MXN];
int timer=0;

template <class T> class LCASegment {
  private:
	const T DEFAULT = -1;
	vector<T> segtree;
	int len;

  public:
	LCASegment(int len) : len(len), segtree(len * 2, DEFAULT) {}

	int lca(int a,int b){
		if(a==-1) return tin[b];
		if(b==-1) return tin[a];
		return (tin[a]<tin[b]?a:b);
	}

	void set(int ind) {
		ind += len;
		segtree[ind] = tour[ind];
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = lca(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T range_sum(int start, int end) {
		T anc = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { anc =lca(anc,start); }
			if (end % 2 == 1) { anc += lca(anc,end); }
		}
		return anc;
	}
};


void dfs(int x,int p){
	tin[x]=timer;
	tour[timer++]=x;

	for(int&y:arr[x]){
		if(y!=p){
			dfs(y,x);
			tour[timer++]=x;
		}
	}
}

void solve(){
    cin>>n>>q;
    fr(i,2,n+1){
    	ll s; cin>>s;
    	arr[i].push_back(s);
    	arr[s].push_back(i);
    }

    dfs(1,0);

    LCASegment<ll> lca(n);
    fr(i,1,n+1) lca.set(i);

    fr(i,0,q){
    	int f,s; cin>>f>>s;
    	cout<<lca.range_sum(f,s-1)<<nL;
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