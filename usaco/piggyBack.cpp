/** 
 immortalzodd
 07.06.2024 12:13:02
 piggyBack
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

ll n,m;
vector<vi> arr;
vector<vi> dist;

void bfs(int x,int ix){
	queue<pii> qs;
	vector<bool> visited(n,false);
	qs.push({x,0});
	visited[x]=true;
	while(!qs.empty()){
		int u=qs.front().first;
		int d=qs.front().second;
		qs.pop();
		dist[u][ix]=d;
		for(int&v:arr[u]){
			if(!visited[v]){
				visited[v]=true;
				qs.push({v,d+1});
			}
		}
	}
}

void solve(){
    ll b,e,p;
    cin>>b>>e>>p>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    dist.assign(n,vi(3,0));

    bfs(0,0);
    bfs(1,1);
    bfs(n-1,2);

    ll ans=INT_MAX,energy=0;
    fr(i,0,n){
    	energy=b*dist[i][0]+e*dist[i][1]+p*dist[i][2];
    	ans=min(ans,energy);
    }
    cout<<ans<<nL;
}

int main(){
	freopen("piggyback.in","r",stdin);
	freopen("piggyback.out","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}