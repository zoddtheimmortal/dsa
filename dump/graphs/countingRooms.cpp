/** 
 immortalzodd
 29.06.2024 16:05:17
 countingRooms
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
vector<string> arr;
vector<vi> vis;
vector<pair<int,int>> disp={{-1,0},{1,0},{0,1},{0,-1}};

void dfs(int r,int c){
	if(r<0||r>=n||c<0||c>=m||vis[r][c]||arr[r][c]!='.') return;
	vis[r][c]=1;
	for(auto[dx,dy]:disp){
		dfs(r+dx,c+dy);
	}
}

void solve(){
    cin>>n>>m;
    arr.resize(n); for(string&s:arr) cin>>s;

    vis.assign(n,vi(m,0));

    ll ans=0;
    fr(i,0,n){
    	fr(j,0,m){
    		if(!vis[i][j]&&arr[i][j]=='.'){
    			dfs(i,j);
    			ans++;
    		}
    	}
    }
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