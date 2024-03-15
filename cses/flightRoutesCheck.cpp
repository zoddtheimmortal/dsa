/** 
 immortalzodd
 28.02.2024 22:53:43
 flightRoutesCheck
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

ll n,m;
vi arr[100005][2];
vector<bool> visited;

void dfs(int sv,int g){
	visited[sv]=true;
	for(auto&x:arr[sv][g]){
		if(!visited[x]) dfs(x,g);
	}
}

void checkRoutes(){
	visited.resize(n);
	fill(all(visited),false);
	dfs(0,0);

	fr(i,0,n){
		if(visited[i]==false){
			cout<<"NO\n";
			cout<<1<<" "<<i+1<<nL;
			return;
		}
	}

	fill(all(visited),false);
	dfs(0,1);
	fr(i,0,n){
		if(visited[i]==false){
			cout<<"NO\n";
			cout<<i+1<<" "<<1<<nL;
			return;
		}
	}
	cout<<"YES"<<nL;
}

void solve(){
    cin>>n>>m;
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[f-1][0].push_back(s-1);
    	arr[s-1][1].push_back(f-1);
    }
    checkRoutes();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}