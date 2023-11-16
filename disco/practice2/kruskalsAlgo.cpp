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

struct node{
	int u,v,w;
};

bool compare(struct node e1,struct node e2){
	return e1.w<e2.w;
}

int getParent(vi parent,int n){
	if(n==parent[n]) return n;
	return getParent(parent,parent[n]);
}

ll kruskalAlgo(v(struct node) arr,int n){
	sort(all(arr),compare);
	vi parent(n,0);
	fr(i,0,n) parent[i]=i;
	ll edgeCount=0,k=0,minCost=0;
	while(edgeCount<n-1){
		if(!(getParent(parent,arr[k].u)==getParent(parent,arr[k].v))){
			minCost+=arr[k].w;
			parent[arr[k].u]=arr[k].v;
			edgeCount++;
		}
		k++;
	}
	return minCost;
}


void solve(){
     ll n,e; cin>>n>>e;
     v(struct node) arr(e);
     fr(i,0,e){
     	cin>>arr[i].u>>arr[i].v>>arr[i].w;
     	arr[i].u-=1,arr[i].v-=1;
     }
     cout<<kruskalAlgo(arr,n)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}