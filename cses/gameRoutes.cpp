/** 
 immortalzodd
 14.04.2024 19:41:56
 gameRoutes
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

const unsigned int MOD=1e9+7;

vector<vi> arr;
vi path;

void solve(){
    ll n,m; cin>>n>>m;
    arr.resize(n);
    path.assign(n,0);

    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    }

    vi indeg(n,0);
    fr(i,0,n){
    	for(int&x:arr[i]) indeg[x]++;
    }

	queue<int> qs;
	fr(i,0,n) if(indeg[i]==0) qs.push(i);
    path[0]=1;

    while(!qs.empty()){
    	int v=qs.front();
    	qs.pop();
    	for(int&x:arr[v]){
    		path[x]=(path[x]+path[v])%MOD;
    		indeg[x]--;
    		if(indeg[x]==0){
    			qs.push(x);
    		}
    	}
    }

    cout<<path[n-1]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}