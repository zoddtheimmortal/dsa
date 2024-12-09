/** 
 immortalzodd
 06.06.2024 22:33:04
 rottenOranges
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

vi dx={1,0,-1,0},dy={0,-1,0,1};

int orangesRotting(vector<vector<int>>& arr) {
	int n=arr.size(),m=arr[0].size();
	vector<vector<int>> grid=arr;
	queue<pair<int,int>> qs;
	int fresh=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==2){
				qs.push({i,j});
			}
			if(grid[i][j]==1){
				fresh++;
			}
		}
	}
	int ans=0;
	if(fresh==0) return 0;
	if(qs.empty()) return -1;

	while(!qs.empty()){
		int size=qs.size();
		while(size--){
			int r=qs.front().first;
			int c=qs.front().second;
			qs.pop();

			for(int i=0;i<4;i++){
				r=r+dx[i]; c=c+dy[i];
				cout<<r<<" "<<c<<nL;
				if(r<0||r>=n||c<0||c>=m||grid[r][c]==0||grid[r][c]==2) continue;
				grid[r][c]=2;
				qs.push({r,c});
				fresh--;
			}
		}
		ans++;
	}
	cout<<fresh<<nL;
	if(fresh==0) return ans-1;
	return -1;
}

void solve(){
	ll n,m; cin>>n>>m;
	vector<vi> arr(n,vi(m,0));
	fr(i,0,n){
		fr(j,0,m) cin>>arr[i][j];
	}
	cout<<orangesRotting(arr)<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}