/** 
 immortalzodd
 14.04.2024 19:11:09
 roundTripII
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

vi cycle;
vector<vi> arr;
vector<bool> visited,on_stack;

bool dfs(int x){
	visited[x]=on_stack[x]=true;
	for(int&y:arr[x]){
		if(on_stack[y]){
			cycle.push_back(y);
			on_stack[x]=on_stack[y]=false;
			return true;
		}
		else if(!visited[y]){
			if(dfs(y)){
				cycle.push_back(y);
				if(on_stack[x]){
					on_stack[x]=false;
					return true;
				}else return false;
			}
		}

		if(!cycle.empty()) return false;
	}
	on_stack[x]=false;
	return false;
}

void solve(){
    ll n,m; cin>>n>>m;
    arr.resize(n);

    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    }

    visited.assign(n,false);
    on_stack.assign(n,false);
    for(int i=0;i<n&&cycle.empty();i++) dfs(i);

    if(cycle.empty()) cout<<"IMPOSSIBLE"<<nL;
	else{
		cout<<cycle.size()+1<<nL;
		cout<<cycle[0]+1<<" ";
		reverse(all(cycle));
		for(int&x:cycle) cout<<x+1<<" ";
		cout<<nL;
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}