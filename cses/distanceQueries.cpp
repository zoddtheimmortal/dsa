/** 
 immortalzodd
 24.07.2024 00:15:19
 distanceQueries
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

const int MXN=2e5+5,MXE=1+log2(MXN);
int up[MXN][MXE];
ll n,q;
vi arr[MXN];
int depth[MXN];

void dfs(int x,int p,int d){
	depth[x]=d;
	for(int&y:arr[x]){
		if(y!=p){
			up[y][0]=x;
			dfs(y,x,d+1);
		}
	}
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
	if(x==y) return y;

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
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    dfs(1,0,0);
    fr(i,1,MXE){
    	fr(j,1,n+1){
    		up[j][i]=up[up[j][i-1]][i-1];
    	}
    }

    fr(i,0,q){
    	int a,b; cin>>a>>b;
    	int c=lca(a,b);
    	cout<<depth[a]+depth[b]-2*depth[c]<<nL;
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