/** 
 immortalzodd
 29.06.2024 22:27:09
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,m;
vector<vi> arr;
vi vis,cycle,ss;

bool dfs(int x){
	vis[x]=ss[x]=1;
	for(int&y:arr[x]){
		if(ss[y]){
			cycle.push_back(y);
			ss[x]=ss[y]=0;
			return true;
		}
		else if(!vis[y]){
			if(dfs(y)){
				cycle.push_back(y);
				if(ss[x]){
					ss[x]=false;
					return true;
				} else return false;
			}
		}
		if(!cycle.empty()) return false;
	}
	ss[x]=0;
	return false;
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    vis.assign(n,0);
    ss.assign(n,0);
    fr(i,0,n){
    	dfs(i);
    	if(!cycle.empty()) break;
    }

    if(cycle.empty()){
    	cout<<"IMPOSSIBLE"<<nL;
    	return;
    }
    cout<<cycle.size()+1<<nL;
    cout<<cycle[0]+1<<" ";
    reverse(all(cycle));
    for(int&x:cycle) cout<<x+1<<" ";
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}