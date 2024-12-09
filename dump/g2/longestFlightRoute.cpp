/** 
 immortalzodd
 17.08.2024 09:22:04
 longestFlightRoute
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
	}

	vi indeg(n,0);

	fr(i,0,n){
		for(auto&x:arr[i]) indeg[x]++;
	}

	queue<int> qs;
	fr(i,0,n) if(indeg[i]==0) qs.push(i);

	vi dp(n,INT_MIN),parent(n,-1);
	dp[0]=1;
	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		for(int&u:arr[v]){
			if(dp[u]<1+dp[v]){
				dp[u]=1+dp[v];
				parent[u]=v;
			}
			if(--indeg[u]==0){
				qs.push(u);
			}
		}
	}

	if(dp[n-1]<0){
		cout<<"IMPOSSIBLE"<<nL;
		return;
	}

	int len=dp[n-1],curr=n-1;
	cout<<len<<nL;
	vi path;
	while(len--){
		path.push_back(curr+1);
		curr=parent[curr];
	}

	reverse(all(path));
	for(int&x:path) cout<<x<<" ";
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