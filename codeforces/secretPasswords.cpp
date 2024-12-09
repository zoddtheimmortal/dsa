/** 
 immortalzodd
 14.07.2024 23:12:14
 secretPasswords
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

ll n;
vi parent,sz;
unordered_map<char,int> mp;

int find(int x){
	while(x!=parent[x]) x=parent[x];
	return x;
}

bool unite(int x,int y){
	x=find(x); y=find(y);
	if(x==y) return false;
	if(sz[x]<sz[y]) swap(x,y);
	parent[y]=x;
	sz[x]+=sz[y];
	return true;
}

void solve(){
    cin>>n;
    parent.assign(n,0); sz.assign(n,1);
    fr(i,0,n) parent[i]=i;

    ll ans=n;
    fr(i,0,n){
    	string s; cin>>s;
    	for(char&c:s){
    		if(mp.find(c)!=mp.end()){
    			ans-=unite(i,mp[c]);
    		}
    		else mp[c]=i;
    	}
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}