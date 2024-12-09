/** 
 immortalzodd
 13.06.2024 09:31:52
 roundTrip
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

#define N 100005

ll n,m;
vi arr[N];
bool vis[N];
vi cycle;

bool dfs(int x,int p){
	vis[x]=true;
	for(int&y:arr[x]){
		cycle.push_back(y);
		if(!vis[x]){
			if(dfs(y,x)) return true;
		}
		else if(y!=p) return true;
		cycle.pop_back();	
	}
	return false;
}

void solve(){
	cin>>n>>m;
	fr(i,0,m){
		ll f,s; cin>>f>>s;
		arr[--f].push_back(--s);
		arr[s].push_back(f);
	}
	fr(i,0,n){
		cycle.push_back(i);
		if(!vis[i]&&dfs(i,0)){
			cout<<cycle.size()<<nL;
			for(int&x:cycle) cout<<x+1<<" ";
			cout<<nL;
			return;
		}
		cycle.pop_back();
	}
	cout<<"IMPOSSIBLE"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}