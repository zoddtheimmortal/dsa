#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void getPathDFS(vector<vi>& arr,int n,int sv,int ev,vector<bool>& visited,vi& path){
    visited[sv]=true;
	if(sv==ev){
		path.pb(ev);
		return;
	}
	fr(i,0,n){
		if(i==sv) continue;
		if(arr[sv][i]==1 && !visited[i]){
			getPathDFS(arr,n,i,ev,visited,path);
			if(!path.empty()) break;
		}
	}
    if(!path.empty()){
        path.pb(sv);
        return;
    }
}

void solve(){
    ll n,e; cin>>n>>e;
    vector<vi> arr(n,vi(n,0));
    fr(i,0,e){
    	ll f,s;
    	cin>>f>>s;
    	arr[f][s]=1;
    	arr[s][f]=1;
    } 
    int sv,ev; cin>>sv>>ev;
    vector<bool> visited(n,false);
    vi path;
    getPathDFS(arr,n,sv,ev,visited,path);
    rep(it,path) cout<<it<<" ";
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