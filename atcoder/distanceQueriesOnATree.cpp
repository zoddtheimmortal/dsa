/** 
 immortalzodd
 24.07.2024 18:21:04
 distanceQueriesOnATree
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

template<class T> class BIT{
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size+1), arr(size) {}

	void set(int ind,int val) {add(ind,val - arr[ind]);}

	void add(int ind,int val){
		arr[ind]+=val;
		ind++;
		for (;ind<=size;ind+=ind&-ind){bit[ind] += val;}
	}

	T pref_sum(int ind) {
		ind++;
		T total=0;
		for (;ind>0;ind-=ind&-ind){total+=bit[ind];}
		return total;
	}
};

ll n,q;
const int MXN=2e5+5,MXE=1+log2(MXN);
vector<pii> arr[MXN];
int up[MXN][MXE],in_v[MXN];
int st[MXN],en[MXN],depth[MXN],edgewt[MXN];
int timer=0;
BIT<ll> bit(MXN);

void dfs(int x,int p,int d){
	depth[x]=d;
	st[x]=timer++;
	up[x][0]=p;

	for(auto[y,i]:arr[x]){
		if(y!=p){
			dfs(y,x,d+1);
			in_v[i]=y;
		}
	}
	en[x]=timer;
}

int jump(int x,int k){
	fr(i,0,MXE){
		if(k&(1LL<<i)) x=up[x][i];
	}
	return x;
}

int lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	a=jump(a,depth[a]-depth[b]);
	if(a==b) return a;

	for(int i=MXE-1;i>=0;i--){
		if(up[a][i]!=up[b][i]){
			a=up[a][i];
			b=up[b][i];
		}
	}
	return up[a][0];
}

void solve(){
    cin>>n;
    fr(i,1,n){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[f].push_back({s,i});
    	arr[s].push_back({f,i});
    	edgewt[i]=w;
    }

    dfs(1,1,0);

    fr(i,1,MXE){
    	fr(j,1,n+1){
    		up[j][i]=up[up[j][i-1]][i-1];
    	}
    }

    fr(i,1,n){
    	bit.set(st[in_v[i]],edgewt[i]);
    	bit.set(en[in_v[i]],-edgewt[i]);
    }

    cin>>q;
    fr(i,0,q){
    	int t,a,b; cin>>t>>a>>b;
    	if(t==1){
    		bit.set(st[in_v[a]],b);
    		bit.set(en[in_v[a]],-b);
    	}
    	else{
    		int c=lca(a,b);
    		cout<<bit.pref_sum(st[a])+
    			bit.pref_sum(st[b])-
    				2*bit.pref_sum(st[lca(a,b)])<<nL;
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