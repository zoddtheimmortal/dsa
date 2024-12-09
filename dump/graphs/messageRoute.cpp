/** 
 immortalzodd
 29.06.2024 17:14:04
 messageRoute
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
vector<vi> arr;

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    vi vis(n,0);
    queue<int> qs;
    qs.push(0);
    vis[0]=1;

    map<int,int> mp;
    mp[0]=0;

    while(!qs.empty()){
    	int v=qs.front();
    	qs.pop();
    	for(int&u:arr[v]){
    		if(!vis[u]){
    			qs.push(u);
    			vis[u]=1;
    			mp[u]=v;
    		}
    	}
    }

    if(!vis[n-1]){
    	cout<<"IMPOSSIBLE"<<nL;
    	return;
    }
    vi path;
    int x=n-1;
    while(x!=0){
    	path.push_back(x);
    	x=mp[x];
    }
    path.push_back(0);
    reverse(all(path));
    cout<<path.size()<<nL;
    for(int&x:path) cout<<x+1<<" ";
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}