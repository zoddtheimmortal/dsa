/** 
 immortalzodd
 15.04.2024 14:22:12
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

#define S 0

void solve(){
    ll n,m; cin>>n>>m;
    vector<vi> arr(n);

    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }

    vector<bool> visited(n,false);
    queue<int> qs;
    map<int,int> mp;

    qs.push(S);
    visited[S]=true;
    mp[S]=-1;

    while(!qs.empty()){
    	int v=qs.front();
    	qs.pop();
    	for(int&x:arr[v]){
    		if(!visited[x]){
    			qs.push(x);
    			visited[x]=true;
    			mp[x]=v;
    		}
    		if(visited[n-1]) break;
    	}
    }

    if(!visited[n-1]) cout<<"IMPOSSIBLE"<<nL;
    else{
    	vi path;
    	int a=n-1;
    	while(a!=-1){
    		path.push_back(a);
    		a=mp[a];
    	}

    	reverse(all(path));
    	cout<<path.size()<<nL;
    	for(int&x:path) cout<<x+1<<" ";
    	cout<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}