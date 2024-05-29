/** 
 immortalzodd
 29.05.2024 22:31:22
 bfs
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

#define S 0

ll n,m;
vector<vi> arr;

void bfs(int x){
	vector<bool> visited(n,false);
	queue<int> qs;
	qs.push(x);
	visited[x]=true;

	while(!qs.empty()){
		int v=qs.front();
		cout<<v<<" ";
		qs.pop();
		for(int&u:arr[v]){
			if(!visited[u]){
				visited[u]=true;
				qs.push(u);
			}
		}
	}
	cout<<nL;
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    bfs(S);
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}