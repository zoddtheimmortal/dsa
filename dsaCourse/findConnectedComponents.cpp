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

vi markBFS(v(vi) &arr,int n,int sv,vector<bool> &visited){
	vi path;
	queue<int> qs;
	visited[sv]=true;
	qs.push(sv);
	path.pb(sv);
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				qs.push(i);
				visited[i]=true;
				path.pb(i);
			}
		}
	}
	return path;
}

v(vi) getComponents(v(vi) arr,int n,int sv){
	v(vi) components;
	vector<bool> visited(n,false);
	fr(i,0,n){
		if(!visited[i]){
			vi path=markBFS(arr,n,i,visited);
			components.pb(path);
		}
	}
	return components;
}

void solve(){
    ll n,e; cin>>n>>e;
    v(vi) arr(n,vi(n,0));
    fr(i,0,e){
    	ll f,s;
    	cin>>f>>s;
    	arr[f][s]=1;
    	arr[s][f]=1;
    }
    v(vi) components=getComponents(arr,n,0);
    rep(k,components){
    	rep(it,k){
    		cout<<it<<" ";
    	}
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