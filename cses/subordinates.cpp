/** 
 immortalzodd
 09.04.2024 21:51:08
 subordinates
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

ll n;
vector<vi> arr;
vi ans;
vector<bool> visited;

void dfs(int x){
	visited[x]=true;

	for(auto&y:arr[x]){
		if(!visited[y]){
			dfs(y);
			ans[x]+=ans[y]+1;
		}
	}
}

void solve(){
    cin>>n;
    arr.resize(n);
    visited.resize(n);
    ans.resize(n);
    fill(all(visited),false);
    fill(all(ans),0);

    fr(i,1,n){
    	ll x; cin>>x;
    	arr[x-1].push_back(i);
    }

    dfs(0);
    for(auto&x:ans) cout<<x<<" ";
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