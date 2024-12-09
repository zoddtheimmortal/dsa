/** 
 immortalzodd
 29.06.2024 20:59:40
 roadReparation
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

struct edge{
	ll f,s,w;
};

ll n,m;
vector<edge> arr;
vi parent,sizes;

int find(int x){
	while(x!=parent[x]) x=parent[x];
	return x;
}

bool unite(int x,int y){
	x=find(x); y=find(y);
	if(x==y) return false;
	if(sizes[x]<sizes[y]) swap(x,y);
	sizes[x]+=sizes[y];
	parent[y]=x;
	return true;
}

void solve(){
    cin>>n>>m;
    arr.resize(m);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[i]=(edge){--f,--s,w};
    }
    parent.assign(n,0); sizes.assign(n,1);
    fr(i,0,n) parent[i]=i;

    sort(all(arr),[&](const edge &a,const edge &b){return a.w<b.w;});
    ll cost=0,added=0;
    for(edge&e:arr){
    	bool status=unite(e.f,e.s);
    	cost+=status*e.w;
    	added+=status;
    }
    if(added!=n-1){
    	cout<<"IMPOSSIBLE"<<nL;
    	return;
    }
    cout<<cost<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}