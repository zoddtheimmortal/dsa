/** 
 immortalzodd
 14.06.2024 21:40:20
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

ll n,q;
vi linked,sizes;
priority_queue<int> pq;

int find(int x){
	while(x!=linked[x]) x=linked[x];
	return x;
}

bool join(int x,int y){
	x=find(x); y=find(y);
	if(x==y) return false;
	if(sizes[x]<sizes[y]) swap(x,y);
	sizes[x]+=sizes[y];
	pq.push(sizes[x]);
	linked[y]=x;
	return true;
}

void solve(){
    cin>>n>>q;
    linked.resize(n); sizes.assign(n,1);
    fr(i,0,n) linked[i]=i;
    int comp=n;
    while(q--){
    	int u,v; cin>>u>>v;
    	if(join(--u,--v)) comp--;
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