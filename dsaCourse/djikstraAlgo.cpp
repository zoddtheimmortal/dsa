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

int getMinVertex(vi dist,int n,v(bool) &visited){
	int minVertex=-1;
	fr(i,0,n){
		if(!visited[i] && ((minVertex==-1)||(dist[minVertex]>dist[i]))){
			minVertex=i;
		}
	}
	return minVertex;
}

vi djPath(v(vi) arr,int n,int sv){
	vi dist=vi(n,INT_MAX);
	v(bool) visited(n,false);
	dist[sv]=0;

	fr(k,0,n-1){
		int minVertex=getMinVertex(dist,n,visited);
		visited[minVertex]=true;
		fr(i,0,n){
			if(!visited[i] && arr[minVertex][i]!=0){
				if(dist[i]>dist[minVertex]+arr[minVertex][i]){
					dist[i]=dist[minVertex]+arr[minVertex][i];
				}
			}
		}
	}

	return dist;
}

void solve(){
    ll n,e; cin>>n>>e;
    v(vi) arr(n,vi(n,0));
    fr(i,0,e){
    	ll f,s,w;
    	cin>>f>>s>>w;
    	arr[f][s]=w;
    	arr[s][f]=w;
    } 
    ll sv; cin>>sv;
    vi dist=djPath(arr,n,sv);
    fr(i,0,dist.size()){
    	cout<<i<<" "<<dist[i]<<nL; 
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