/** 
 immortalzodd
 11.06.2024 22:39:07
 monsters
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

#define MAX_N 1000

ll n,m;
pii A;
vector<string> grid;
vector<vector<char>> path;
vector<vl> dist,monster;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

void bfs(int r,int c){
	vector<vb> vis(n,vb(m,false));
	queue<pii> qs;
	qs.push({r,c});
	vis[r][c]=true;
	monster[r][c]=0;

	while(!qs.empty()){
		auto [i,j]=qs.front();
		qs.pop();

		vis[i][j]=true;
		fr(k,0,4){
			int p=i+dx[k],q=j+dy[k];
			if(p<0||p>=n||q<0||q>=m
				||grid[p][q]=='#'||vis[p][q]) continue;
			monster[p][q]=min(monster[p][q],1+monster[i][j]);
			qs.push({p,q});
		}
	}
}

void solve(){
    cin>>n>>m;
    grid.resize(n); for(string&s:grid) cin>>s;
    path=vector<vector<char>>(n,vector<char>(m,'X'));
    monster=vector<vl>(n,vl(m,INT64_MAX));
    dist=vector<vl>(n,vl(m,INT64_MAX));
    fr(i,0,n){
    	fr(j,0,m){
    		if(grid[i][j]=='M') bfs(i,j);
    		if(grid[i][j]=='A') A={i,j};
    	}
    }

    queue<pii> qs;
    vector<vb> vis(n,vb(m,false));
    vis[A.first][A.second]=true;
    qs.push({A.first,A.second});

    string mp[]={"XUX","LXR","XDX"};

    while(!qs.empty()){
    	auto [r,c]=qs.front();
    	qs.pop();
    	vis[r][c]=true;
    	fr(i,0,4){
    		int p=r+dx[i],q=c+dy[i];
    		if(p<0||p>=n||q<0||q>=m
				||grid[p][q]=='#'||vis[p][q]) continue;
			dist[p][q]=min(dist[p][q],dist[r][c]+1);
			if(dist[p][q]>=monster[p][q]) continue;
			path[p][q]=mp[1+dx[i]][1+dy[i]];
			qs.push({p,q});
    	}
    }

    bool reach=false;
    pii reached;
    fr(i,0,n){
    	if(reach) break;
    	if(vis[i][0]==true){
    		reach=true;
    		reached={i,0};
    		break;
    	}
    	if(vis[i][m-1]==true){
    		reach=true;
    		reached={i,m-1};
    		break;
    	}
    }
    fr(j,0,m){
    	if(reach) break;
    	if(vis[0][j]==true){
    		reach=true;
    		reached={0,j};
    		break;
    	}
    	if(vis[n-1][j]==true){
    		reach=true;
    		reached={n-1,j};
    		break;
    	}
    }
    
    int r=reached.first,c=reached.second;
    string route="";
    while(r!=A.first||c!=A.second){
    	char x=path[r][c];
    	route+=x;
    	if(x=='R') c--;
    	if(x=='L') c++;
    	if(x=='U') r++;
    	if(x=='D') r--;
    }

    cout<<(reach?"YES":"NO")<<nL;
    cout<<route.size()<<nL<<route<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}