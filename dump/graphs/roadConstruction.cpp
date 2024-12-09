/** 
 immortalzodd
 29.06.2024 21:10:06
 roadConstruction
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

ll n,m;
vi parent,sizes;
priority_queue<int> pq;

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
	pq.push(sizes[x]);
    return true;
}

void solve(){
    cin>>n>>m;
    parent.assign(n,0); sizes.assign(n,1);
    fr(i,0,n) parent[i]=i;
    ll comp=n;
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	bool status=unite(--f,--s);
    	comp-=status;
    	cout<<comp<<" "<<pq.top()<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}