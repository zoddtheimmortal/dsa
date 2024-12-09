/** 
 immortalzodd
 24.07.2024 23:45:26
 cowland
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
const int MXN=1e5+5,MXE=1+log2(MXN);
vi arr[MXN];
int st[MXN],en[MXN],depth[MXN];
ll up[MXN][MXE],bit[2*MXN],vals[MXN];
int timer=0;

void update(int k,ll x){
	for(k+=1;k<MXN;k+=k&-k) bit[k]^=x;
}

ll query(int k){
	ll xo=0;
	for(;k>0;k-=k&-k) xo^=bit[k];
	return xo;
}

void dfs(int x,int p){
	depth[x]=1+depth[p];
	up[x][0]=p;
	st[x]=timer++;

	for(int&y:arr[x]){
		if(y!=p) dfs(y,x);
	}
	en[x]=timer-1;
}

int jump(int x,int k){
	fr(i,0,MXE){
		if(k&(1LL<<i)) x=up[x][i];
	}
	return x;
}

int lca(int x,int y){
	if(depth[x]<depth[y]) swap(x,y);
	x=jump(x,depth[x]-depth[y]);
	if(x==y) return x;

	for(int i=MXE-1;i>=0;i--){
		if(up[x][i]!=up[y][i]){
			x=up[x][i];
			y=up[y][i];
		}
	}
	return up[x][0];
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

    fr(i,1,MXE){
    	fr(j,1,n+1){
    		up[j][i]=up[up[j][i-1]][i-1];
    	}
    }

    fr(i,1,n+1){
    	update(st[i],vals[i]);
    	update(en[i]+1,vals[i]);
    }

    fr(i,0,q){
    	int t,x,y; cin>>t>>x>>y;
    	if(t==1){
    		update(st[x],vals[x]^y);
    		update(en[x]+1,vals[x]^y);
    		vals[x]=y;
    	}
    	else{
    		int z=lca(x,y);
    		cout<<(query(st[x]+1)^query(st[y]+1)^vals[z])<<nL;
    	}
    }
}

int main(){
    fast_io;
    ll t=1;
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);
    // cin>>t;

    while(t--){
        solve();
    }
}