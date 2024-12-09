/** 
 immortalzodd
 05.06.2024 09:58:59
 treeDistancesII
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
vector<vi> arr;
vi cnt,dist;

int dfs(int x,int p,int d){
	cnt[x]=1;
	int q=0;
	for(int&y:arr[x]){
		if(y==p) continue;
		int p=dfs(y,x,d+1);
		cnt[x]+=cnt[y];
		q+=p+cnt[y];
	}
	return q;
}

void solve(){
    cin>>n;
    arr.resize(n); cnt.assign(n,0); dist.assign(n,0);
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    fr(i,0,n){
    	int x=dfs(i,i,0);
    	cout<<x<<" ";
    }
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