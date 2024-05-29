/** 
 immortalzodd
 15.04.2024 21:17:51
 labyrinth
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using ii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define f first
#define s second

bool visited[1000][1000];
int parent[1000][1000];
vi dx={1,0,-1,0};
vi dy={0,-1,0,1};
char arr[1000][1000];

void solve(){
    ll n,m; cin>>n>>m;
    ii a,b;

    fr(i,0,n){
    	fr(j,0,m){
    		cin>>arr[i][j];
    		if(arr[i][j]=='A') a={i,j};
    		if(arr[i][j]=='B') b={i,j};
    	}
    }

    queue<ii> qs;
    visited[a.f][a.s]=true;
    qs.push(a);

    while(!qs.empty()){
    	ii u=qs.front();
    	qs.pop();
    	fr(i,0,4){
    		ii v={u.f+dx[i],u.s+dy[i]};
    		if(v.f<0||v.f>=n||v.s<0||v.s>=m) continue;
    		if(visited[v.f][v.s]) continue;
    		if(arr[v.f][v.s]=='#') continue;

    		visited[v.f][v.s]=true;
    		parent[v.f][v.s]=i;
    		qs.push(v);
    	}
    }

    if(!visited[b.f][b.s]) cout<<"NO"<<nL;
    else{
    	cout<<"YES"<<nL;
    	vi path;
    	string dir="DLUR";
    	while(b!=a){
    		int p=parent[b.f][b.s];
    		path.push_back(p);
    		b={b.f-dx[p],b.s-dy[p]};
    	}

    	reverse(all(path));
    	cout<<path.size()<<nL;
    	for(int&x:path) cout<<dir[x];
    	cout<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}