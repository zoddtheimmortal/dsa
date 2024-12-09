/** 
 immortalzodd
 12.07.2024 19:29:09
 companyQueriesII
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

const int MXN=2e5+5,MXE=log2(MXN)+1;
ll n,q;
vector<vi> arr;
vi depth;
int up[MXN][MXE];

void dfs(int x,int p){
	depth[x]=1+depth[p];
	for(int&y:arr[x]){
		if(y!=p) dfs(y,x);
	}
}

int jump(int x,int k){
	for(int i=0;i<MXE;i++){
		if(k&(1LL<<i)) x=up[x][i];
		if(x==-1) break;
	}
	return x;
}

int lca(int x,int y){
	if(depth[x]<depth[y]) return lca(y,x);
	x=jump(x,depth[x]-depth[y]);
	if(y==x) return y;

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
    memset(up,-1,sizeof(up));
    depth.assign(n+1,-1);
    arr.resize(n+1);

    fr(i,2,n+1){
    	ll x; cin>>x;
    	up[i][0]=x;
    	arr[i].push_back(x);
    	arr[x].push_back(i);
    }

    dfs(1,1);

    fr(i,1,MXE){
    	fr(j,1,n+1){
    		if(up[j][i-1]!=-1) up[j][i]=up[up[j][i-1]][i-1];
    	}
    }

    while(q--){
    	ll x,y; cin>>x>>y;
    	cout<<lca(x,y)<<nL;
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