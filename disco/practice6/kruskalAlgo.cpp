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

int getParent(int n,vi parent){
	if(n==parent[n]) return n;
	return getParent(parent[n],parent);
}

int kruskalAlgo(v(struct node) arr,int n){
	sort(all(arr),compare);
	vi parent(n,0);
	fr(i,0,n) parent[i]=i;

	int edgeCount=0,k=0,cost=0;
	while(edgeCount<n-1){
		if(getParent(arr[k].u,parent)!=getParent(arr[k].v,parent)){
			edgeCount++;
			cost+=arr[k].w;
			parent[arr[k].u]=arr[k].v;
		}
		k++;
	}
	return cost;
}

void solve(){
     ll n,e;
     cin>>n>>e;
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