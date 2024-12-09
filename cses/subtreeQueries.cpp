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

    BIT<ll> bit(n);

    fr(i,0,n) bit.set(s[i],vals[i]);

    fr(i,0,q){
    	ll t; cin>>t;
    	if(t==1){
    		int x,y; cin>>x>>y;
    		bit.set(s[--x],y);
    	}
    	if(t==2){
    		int node; cin>>node;
    		ll endsum=bit.pref_sum(e[--node]-1),startsum=0;
    		if(s[node]!=0) startsum=bit.pref_sum(s[node]-1);
    		cout<<endsum-startsum<<nL;
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