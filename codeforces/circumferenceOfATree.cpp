/** 
 immortalzodd
 22.07.2024 19:28:32
 circumferenceOfATree
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

const int MX=3e5+5;
ll n;
vi arr[MX];
int depth[MX];

int dfs(int x,int p,int d){
	depth[x]=d;
	int opt=-1;
	for(int&y:arr[x]){
		if(y!=p){
			int z=dfs(y,x,d+1);
			if(opt==-1||depth[z]>depth[opt]) opt=z;
		}
	}
	return opt==-1?x:opt;
}

void solve(){
    cin>>n;
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }

    memset(depth,0,sizeof(depth));
    int u=dfs(0,-1,0);
    memset(depth,0,sizeof(depth));
    int v=dfs(u,u,0);

    cout<<3*depth[v]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}