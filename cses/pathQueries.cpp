/** 
 immortalzodd
 24.07.2024 22:36:27
 pathQueries
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
vi arr[MXN];
ll st[MXN],en[MXN],vals[MXN];
ll bit[MXN];
ll timer=1;

void update(int k,int x){
	for(;k<MXN;k+=k&-k) bit[k]+=x;
}

ll query(int k){
	ll sum=0;
	for(;k>0;k-=k&-k) sum+=bit[k];
	return sum;
}

void dfs(int x,int p){
	st[x]=timer++;
	for(int&y:arr[x]){
		if(y!=p) dfs(y,x);
	}
	en[x]=timer++;
}

void solve(){
    cin>>n>>q;
    fr(i,1,n+1) cin>>vals[i];

    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    dfs(1,1);

    fr(i,1,n+1){
    	update(st[i],vals[i]);
    	update(en[i],-vals[i]);
    }

    fr(i,0,q){
    	int t; cin>>t;
    	if(t==1){
    		ll s,x; cin>>s>>x;
    		update(st[s],x-vals[s]);
    		update(en[s],-x+vals[s]);
    		vals[s]=x;
    	}
    	if(t==2){
    		ll s; cin>>s;
    		cout<<query(st[s])<<nL;
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