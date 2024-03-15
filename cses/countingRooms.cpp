/** 
 immortalzodd
 01.03.2024 21:37:24
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

const int MAX_N=1500;

ll n,m;
vector<string> arr(MAX_N);
vector<vector<bool>> visited(MAX_N,vector<bool>(MAX_N,false));

void fill(int i,int j){
	queue<pair<int,int>> qs;
	qs.push({i,j});

	while(!qs.empty()){
		int r=qs.front().first;
		int c=qs.front().second;
		qs.pop();

		if(r>=n||r<0||c>=m||c<0||arr[r][c]!='.'||visited[r][c]) continue;

		visited[r][c]=true;

		qs.push({r-1,c});
		qs.push({r+1,c});
		qs.push({r,c-1});
		qs.push({r,c+1});
	}
}

void solve(){
	cin>>n>>m;
	fr(i,0,n) cin>>arr[i];

	ll ans=0;
	fr(i,0,n){
		fr(j,0,m){
			if(!visited[i][j]&&arr[i][j]=='.'){
				fill(i,j);
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