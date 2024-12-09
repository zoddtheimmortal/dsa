/** 
 immortalzodd
 06.06.2024 21:50:43
 roundDance
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

ll n;
vector<vi> arr;
vector<bool> visited;

bool dfs(int x,int p){
	visited[x]=true;
	for(int&y:arr[x]){
		if(!visited[y]) dfs(y,x);
	}
	return false;
}

void solve(){
	cin>>n;
	arr=vector<vi>(n);
	fr(i,0,n){
		int x; cin>>x;
		arr[i].push_back(--x);
	}
	visited.assign(n,false);
	ll gmax=0;
	fr(i,0,n){
		if(!visited[i]){
			dfs(i,i);
			gmax++;
		}
	}
	cout<<gmax<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}