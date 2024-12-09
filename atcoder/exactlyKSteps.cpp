/** 
 immortalzodd
 24.07.2024 15:42:37
 exactlyKSteps
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
vi arr[MXN];
int depth[MXN];
ll n,q;

int dfs(int x,int p,int d){
	depth[x]=d;
	up[x][0]=p;

	int opt=-1;
	for(int&y:arr[x]){
		if(y!=p){
			int z=dfs(y,x,d+1);
			if(opt==-1||depth[z]>depth[opt]) opt=z;
		}
	}
	return opt==-1?x:opt;
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
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    int ends[2];
    ends[0]=dfs(1,1,0);
    ends[1]=dfs(ends[0],ends[0],0);

    dfs(1,1,0);

    fr(i,1,MXE){
    	fr(j,1,n+1){
    		up[j][i]=up[up[j][i-1]][i-1];
    	}
    }

    cin>>q;
    fr(i,0,q){
    	int a,k; cin>>a>>k;
    	int ans=-1;
    	for(int&b:ends){
    		int c=lca(a,b);
    		int d1=depth[a]-depth[c],d2=depth[b]-depth[c];
    		if(d1>=k) ans=jump(a,k);
    		else if(d1+d2>=k){
    			ans=jump(b,d2+d1-k);
    		}
    		if(ans!=-1) break;
    	}
    	cout<<ans<<nL;
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