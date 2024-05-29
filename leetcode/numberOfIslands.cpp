/** 
 immortalzodd
 28.05.2024 11:19:21
 numberOfIslands
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

void floodFill(int r,int c,vector<vector<char>>&grid){
	int n=grid.size(),m=grid[0].size();
	if(r<0||r>=n||c<0||c>=n||grid[r][c]!='1') return;
	grid[r][c]='0';
	floodFill(r-1,c,grid);
	floodFill(r,c-1,grid);
	floodFill(r+1,c,grid);
	floodFill(r,c+1,grid);
}

int numIslands(vector<vector<char>>& grid) {
	int n=grid.size(),m=grid[0].size();
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='1'){
				cout<<i<<" "<<j<<nL;
				floodFill(i,j,grid);
				ans++;
			}
		}
	}
	return ans;
}

void solve(){
	int n,m; cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m));
	fr(i,0,n){
		fr(j,0,m) cin>>grid[i][j];
	}
	int ans=numIslands(grid);
	cout<<ans<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}