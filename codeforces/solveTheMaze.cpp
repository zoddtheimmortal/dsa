/** 
 immortalzodd
 04.06.2024 22:53:21
 solveTheMaze
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
vector<string> grid;
vector<vector<bool>> visited;
vi dx={-1,0,1,0},dy={0,-1,0,1};

void floodFill(int r,int c){
	if(r<0||r>=n||c<0||c>=m||
		grid[r][c]=='#'||visited[r][c]) return;
	visited[r][c]=true;
	fr(i,0,4) floodFill(r+dx[i],c+dy[i]);
}

void solve(){
    cin>>n>>m;
    grid.resize(n); for(string&s:grid) cin>>s;
    fr(i,0,n){
    	fr(j,0,m){
    		if(grid[i][j]=='B'){
    			fr(p,0,4){
    				int r=i+dx[p],c=j+dy[p];
    				if(r>=0&&r<n&&c>=0&&c<m){
    					if(grid[r][c]=='G'){
    						cout<<"No"<<nL;
    						return;
    					}
    					if(grid[r][c]=='.') grid[r][c]='#';
    				}
    			}
    		}
    	}
    }
    visited.assign(n,vector<bool>(m,false));
    floodFill(n-1,m-1);
    fr(i,0,n){
    	fr(j,0,m){
    		if(grid[i][j]=='G'&&!visited[i][j]){
    			cout<<"No"<<nL;
    			return;
    		}
    	}
    }
    cout<<"Yes"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}