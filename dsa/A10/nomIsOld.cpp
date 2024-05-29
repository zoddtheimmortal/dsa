/** 
 immortalzodd
 11.04.2024 11:40:57
 nomIsOld
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

vector<vi> arr;
vi dist;

int dfs(int x,int p,int d){
	dist[x]=d;
	int opt=-1;

	for(int&y:arr[x]){
		if(y!=p){
			int z=dfs(y,x,d+1);
			if(opt==-1||dist[z]>dist[opt]) opt=z;
		}
	}
	return opt==-1?x:opt;
}

void solve(){
    ll n; cin>>n;
    arr.resize(++n);

    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }	
    dist=vi(n,0);

    int u=dfs(0,0,0);
    int v=dfs(u,u,0);

    cout<<dist[v]+1<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}