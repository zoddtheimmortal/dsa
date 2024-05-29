/** 
 immortalzodd
 11.04.2024 15:14:17
 graphsAreNice
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

void solve(){
    ll n,m,sv,ev; cin>>n>>m>>sv>>ev;
    vector<vi> arr(n);

    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    vector<bool> visited(n,false);
    queue<int> qs;
    map<int,int> mp;
    mp[sv]=-1;

    visited[sv]=true;
    qs.push(sv);

    while(!qs.empty()){
    	int v=qs.front();
    	qs.pop();
    	for(auto&x:arr[v]){
    		if(!visited[x]){
    			visited[x]=true;
    			mp[x]=v;
    			qs.push(x);
    		}
    		if(visited[ev]) break;
    	}
    }

    vi ans(m);
    int c=ev,k=0;
    while(c!=-1){
    	ans[k++]=c;
    	c=mp[c];
    }
    for(int i=k-1;i>=0;i--) cout<<ans[i]<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}