/** 
 immortalzodd
 25.07.2024 10:02:11
 lomsatGelral
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
const int MXN=1e5+5;
vi arr[MXN];
map<ll,ll> colcnt[MXN];
map<ll,ll> sumcnt[MXN];
ll ans[MXN],col[MXN];

void dfs(int x,int p){
	colcnt[x][col[x]]++;
	sumcnt[x][1]+=col[x];

	for(int&y:arr[x]){
		if(y==p) continue;
		dfs(y,x);

		if(colcnt[x].size()<colcnt[y].size()){
			swap(colcnt[x],colcnt[y]);
			swap(sumcnt[x],sumcnt[y]);
		}

		for(auto[c,val]:colcnt[y]){
			if(colcnt[x].count(c)){
				sumcnt[x][colcnt[x][c]]-=c;
			}

			colcnt[x][c]+=val;
			sumcnt[x][colcnt[x][c]]+=c;
		}
	}

	ans[x]=sumcnt[x].rbegin()->second;
}

void solve(){
    cin>>n;
    fr(i,1,n+1) cin>>col[i];
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    dfs(1,0);

    fr(i,1,n+1) cout<<ans[i]<<" ";
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