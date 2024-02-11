/** 
 immortalZodd
 02.02.2024 22:16:51
 buildingRoads
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

vi pairs;

void mark_dfs(vi arr[],ll sv,vector<bool> &visited){
	if(visited[sv]) return;
	visited[sv]=true;

	for(auto x:arr[sv]) mark_dfs(arr,x,visited);
}

void getConComp(vi arr[],ll n){
	ll ans=0;
	vector<bool> visited(n,false);
	fr(i,0,n){
		if(!visited[i]){
			mark_dfs(arr,i,visited);
			pairs.push_back(i+1);
			ans++;
		}
	}
	cout<<ans-1<<nL;
	fr(i,1,pairs.size()){
		cout<<pairs[i-1]<<" "<<pairs[i]<<nL;
	}
}

void solve(){
    ll n,m; cin>>n>>m;
    vi arr[n];
    while(m--){
    	ll f,s; cin>>f>>s;
    	arr[f-1].push_back(s-1);
    	arr[s-1].push_back(f-1);
    }

    getConComp(arr,n);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}