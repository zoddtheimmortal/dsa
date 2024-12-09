/** 
 immortalzodd
 17.07.2024 23:42:18
 treeMatching
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

ll n,ans=0;
vi done;
vector<vi> arr;

void dfs(int x,int p){
	for(int&y:arr[x]){
		if(y!=p){
			dfs(y,x);
			if(!done[y]&&!done[x]) done[y]=done[x]=1,ans++;
		}
	}
}

void solve(){
    cin>>n;
    arr.resize(n);
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    done.assign(n,0);
    dfs(0,-1);
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