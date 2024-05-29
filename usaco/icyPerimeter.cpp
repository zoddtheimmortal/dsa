/** 
 immortalzodd
 12.04.2024 12:00:16
 icyPerimeter
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

vector<string> arr;
vector<vector<bool>> visited;
ll n;

pair<int,int> dfs(int r,int c){
	pair<int,int> ans={0,0};
	stack<pair<int,int>> ss;
	ss.push({r,c});

	while(!ss.empty()){
		r=ss.top().first;
		c=ss.top().second;
		ss.pop();

		if(r<0||r>=n||c<0||c>=n){
			ans.second++;
			continue;
		}
		if(visited[r][c]) continue;
		if(arr[r][c]=='.'){
			ans.second++;
			continue;
		}

		visited[r][c]=true;
		ans.first++;
		ss.push({r+1,c});
		ss.push({r,c+1});
		ss.push({r-1,c});
		ss.push({r,c-1});
	}
	return ans;
}

void solve(){
	cin>>n;
	arr.resize(n);

	fr(i,0,n) cin>>arr[i];

	visited=vector<vector<bool>>(n,vector<bool>(n,false));

	int area=0,peri=0;
	fr(i,0,n){
		fr(j,0,n){
			if(!visited[i][j]&&arr[i][j]=='#'){
				pair<int,int> temp=dfs(i,j);
				if(area==temp.first){
					peri=min(peri,temp.second);
				}
				else{
					area=max(area,temp.first);
					peri=max(peri,temp.second);
				}
			}
		}
	}

	cout<<area<<" "<<peri<<nL;
}

int main(){
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}