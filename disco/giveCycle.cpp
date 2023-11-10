#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

vi path;
void markDFS(v(vi) &arr,int n,int sv,int parent,v(bool) &visited){
	visited[sv]=true;
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			markDFS(arr,n,i,sv,visited);
			if(!path.empty()){
				path.pb(i);
				return;
			}
		}
		else if(i!=parent && arr[sv][i]==1){
			path.pb(i);
			return;
		}
	}
}

void checkCycle(v(vi) arr,int n){
	v(bool) visited(n,false);
	fr(i,0,n){
		if(!visited[i]){
			markDFS(arr,n,i,-1,visited);
			if(!path.empty()) return;
		}
	}
	return;
}

void solve(){
     ll n,e; cin>>n>>e;
     v(vi) arr(n,vi(n,0));
     fr(i,0,e){
     	ll f,s;
     	cin>>f>>s;
     	arr[f-1][s-1]=1;
     	arr[s-1][f-1]=1;
     }
     checkCycle(arr,n);
     if(path.empty()) cout<<-1;
     else{
     	fr(i,0,path.size()-1) cout<<path[i]+1<<" ";
     }
     cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}