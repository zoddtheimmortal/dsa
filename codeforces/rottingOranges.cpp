/** 
 immortalzodd
 05.06.2024 09:43:29
 rottingOranges
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

ll n,m;
vector<vi> grid;
vi dx={-1,0,1,0},dy={0,-1,0,1};

int orangesRotting(vector<vi>&grid){
	int n=grid.size(),m=grid[0].size(),ans=0;
	vector<vector<bool>> visited(n,vector<bool>(m,false));

	fr(i,0,n){
		fr(j,0,m){
			if(grid[i][j]==2&&!visited[i][j]){
				queue<tuple<int,int,int>> ss;
				int prev=0;
				ss.push({i,j,0});
				while(!ss.empty()){
					int r=get<0>(ss.front());
					int c=get<1>(ss.front());
					int p=get<2>(ss.front());
					ss.pop();
					if(r<0||r>=n||c<0||c>=m||visited[r][c]
							||grid[r][c]==0) continue;
					if(prev!=p) ans++;
					visited[r][c]=true;
					fr(i,0,4) ss.push(make_tuple(r+dx[i],c+dy[i],1-p));
					prev=p;
				}
			}
		}
	}
	fr(i,0,n){
		fr(j,0,m) if(grid[i][j]==1&&!visited[i][j]) return -1;
	}
	return ans;
}

void solve(){
    cin>>n>>m;
    grid.resize(n,vi(m,0));
    fr(i,0,n){
    	fr(j,0,m) cin>>grid[i][j];
    }
    cout<<orangesRotting(grid)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}