/** 
 immortalzodd
 24.07.2024 10:42:32
 slothNaptime
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

const int MXN=3e5+5,MXE=1+log2(MXN);
int up[MXN][MXE];
vi arr[MXN];
int depth[MXN];
ll n,q;

void dfs(int x,int p,int d){
	depth[x]=d;
	up[x][0]=p;
	for(int&y:arr[x]){
		if(y!=p) dfs(y,x,d+1);
	}
}

int jump(int x,int k){
	fr(i,0,MXE){
		if(k&(1LL<<i)) x=up[x][i];
	}
	return x>-1?x:0;
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
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    dfs(1,1,0);

    fr(i,1,MXE){
    	fr(j,1,n+1){
    		up[j][i]=up[up[j][i-1]][i-1];
    	}
    }

    cin>>q;
    fr(i,0,q){
    	int a,b,p; cin>>a>>b>>p;
    	int c=lca(a,b);

    	int d1=depth[a]-depth[c],d2=depth[b]-depth[c];
    	if(p>=d1+d2) cout<<b<<nL;
    	else{
    		if(p<=d1) cout<<jump(a,p)<<nL;
    		else cout<<jump(b,d2+d1-p)<<nL;
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