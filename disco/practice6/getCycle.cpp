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
void markCycle(v(vi) arr,int n,int sv,int parent,v(bool) &visited){
	visited[sv]=true;
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			markCycle(arr,n,i,sv,visited);
			if(!path.empty()){
				if(find(all(path),i)==path.end()) path.pb(i);
				return;
			}
		}
		else if(i!=parent && arr[sv][i]==1){
			path.pb(i);
			return;
		}
	}
}

void getCycle(v(vi) arr,int n){
	v(bool) visited(n,false);
	fr(i,0,n){
		if(!visited[i]){
			markCycle(arr,n,i,i,visited);
		}
		if(!path.empty()) return;
	}
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
    getCycle(arr,n);

    if(!path.empty()){
    	rep(it,path) cout<<it+1<<" ";
    }
    else cout<<-1;
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