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

int getMinVertex(v(bool) &visited,vi &weight,int n){
	int minVertex=-1;
	fr(i,0,n){
		if(!visited[i] && ((minVertex==-1)||weight[minVertex]>weight[i])){
			minVertex=i;
		}
	}
	return minVertex;
}

void primsAlgo(v(vi) arr,int n){
	vi parent(n); parent[0]=-1;
	vi weight(n,INT_MAX); weight[0]=0;
	v(bool) visited(n,false);

	fr(i,0,n-1){
		int minVertex=getMinVertex(visited,weight,n);
		visited[minVertex]=true;
		fr(j,0,n){
			if(arr[minVertex][j]!=-1 && !visited[j]){
				if(weight[j]>arr[minVertex][j]){
					weight[j]=arr[minVertex][j];
					parent[j]=minVertex;
				}
			}
		}
	}
	ll cost=0;
	fr(i,0,n) cost+=weight[i];
	cout<<cost<<nL;
}

void solve(){
    ll n,e; cin>>n>>e;
    v(vi) arr(n,vi(n,-1));
    fr(i,0,e){
    	ll f,s,w;
    	cin>>f>>s>>w;
    	arr[f-1][s-1]=w;
    	arr[s-1][f-1]=w;
    } 
    primsAlgo(arr,n);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}