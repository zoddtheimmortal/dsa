/** 
 immortalzodd
 30.06.2024 18:01:56
 maximalRectangle
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

using vi = vector<int>;
int maximalRectangle(vector<vector<char>>& grid) {
	int n=grid.size(),m=grid[0].size();
	vector<vi> dp1(n+1,vi(m+1,0)),dp2(n+1,vi(m+1,0));

	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(grid[i-1][j-1]=='0') continue;
			dp2[i][j]=1+max(dp2[i-1][j],dp2[i][j-1]);
		}
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(grid[i-1][j-1]=='0') continue;
			dp1[i][j]=1+dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
		}
	}
	int ans=0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			cout<<dp1[i][j]<<" ";
		}
		cout<<nL;
	}
	cout<<nL;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			cout<<dp2[i][j]<<" ";
		}
		cout<<nL;
	}
	return 0;
}

void solve(){
	ll n,m; cin>>n>>m;
	vector<vector<char>> arr(n,vector<char>(m));
	fr(i,0,n){
		fr(j,0,m) cin>>arr[i][j];
	}
	cout<<maximalRectangle(arr)<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}