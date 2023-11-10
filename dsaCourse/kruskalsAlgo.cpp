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

struct edge{
	int s,d,w;
};

bool compare(struct edge e1,struct edge e2){
	return e1.w<e2.w;
}

void markParent(vi &parent,int n,int src,int dest){
	fr(i,0,n){
		if(parent[i]==src) parent[i]=dest;
	}
}


void kruskalAlgo(v(struct edge) arr,int n,int e){
	sort(all(arr),compare);
	vi parent(n,0);

	fr(i,0,n){
		parent[i]=i;
	}

	ll minCost=0,eCount=0,k=0;
	while(eCount<n-1 && k<n){
		if(parent[arr[k].s]!=parent[arr[k].d]){
			markParent(parent,n,arr[k].d,arr[k].s);
			cout<<arr[k].s<<" "<<arr[k].d<<" "<<arr[k].w<<nL;

			eCount++;
			minCost+=arr[k].w;
		}
		k++;
	}
	cout<<minCost<<nL;
}

void solve(){
    ll n,e;
    cin>>n>>e; 
    v(struct edge) arr(e);
    fr(i,0,e){
    	ll s,d,w;
    	cin>>s>>d>>w;
    	struct edge e;
    	e.s=s,e.d=d,e.w=w;
    	arr[i]=e;
    }
    kruskalAlgo(arr,n,e);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}