/** 
 immortalzodd
 14.06.2024 21:01:21
 unionfind
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
vi linked,num;

int find(int x){
	while(x!=linked[x]) x=linked[x];
	return x;
}

void join(int x,int y){
	x=find(x); y=find(y);
	if(num[x]<num[y]) swap(x,y);
	num[x]+=num[y];
	linked[y]=x;
}

void solve(){
    cin>>n>>q;
    linked.resize(n); num.resize(n);
    fr(i,0,n) linked[i]=i,num[i]=1;
    while(q--){
    	int t,u,v; cin>>t>>u>>v;
    	if(t==0) join(u,v);
    	if(t==1) cout<<(find(u)==find(v))<<nL;
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