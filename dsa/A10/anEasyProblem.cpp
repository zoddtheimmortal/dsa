/** 
 immortalzodd
 11.04.2024 21:24:47
 anEasyProblem
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
vector<vector<bool>> visited;
ll m,n;

void flood_fill(int r,int c){
	stack<pair<int,int>> ss;
	ss.push({r,c});

	while(!ss.empty()){
		r=ss.top().first;
		c=ss.top().second;
		ss.pop();

		if(r<0||r>=m||c<0||c>=n||visited[r][c]||(arr[r][c]==0)) continue;

		visited[r][c]=true;
		ss.push({r+1,c});
		ss.push({r-1,c});
		ss.push({r,c+1});
		ss.push({r,c-1});
	}
}

void solve(){
    cin>>m>>n;
    arr=vector<vi>(m,vi(n));
    fr(i,0,m){
    	fr(j,0,n) cin>>arr[i][j];
    }

    visited=vector<vector<bool>>(m,vector<bool>(n,false));

    ll ans=0;
    fr(i,0,m){
    	fr(j,0,n){
    		if(!visited[i][j]&&(arr[i][j]==1)){
    			flood_fill(i,j);
    			ans++;
    		}
    	}
    }

    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}