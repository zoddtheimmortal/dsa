/** 
 immortalzodd
 07.06.2024 18:43:29
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
vector<vi> arr,brr;

void solve(){
    cin>>n>>m;
    arr.resize(n);
    brr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	brr[s].push_back(f);
    }
    vi top_sort,indeg(n,0);
    fr(i,0,n){
    	for(int&x:arr[i]) indeg[x]++;
    }

	queue<int> qs;
	fr(i,0,n){
		if(indeg[i]==0) qs.push(i);
	}
	while(!qs.empty()){
		int u=qs.front();
		top_sort.push_back(u);
		qs.pop();
		for(int&v:arr[u]){
			if(--indeg[v]==0){
				qs.push(v);
			}
		}
	}

	vi dp(n,INT_MIN),parent(n,-1);
	dp[0]=1;
	for(int&x:top_sort){
		for(int&y:brr[x]){
			if(dp[x]<1+dp[y]){
				dp[x]=1+dp[y];
				parent[x]=y;
			}
		}
	}
	if(dp[n-1]<0){
		cout<<"IMPOSSIBLE"<<nL;
	}
	else{
		vi route;
		int si=n-1;
		while(si!=-1){
			route.push_back(si);
			si=parent[si];
		}
		reverse(all(route));
		cout<<dp[n-1]<<nL;
		for(int&x:route) cout<<x+1<<" ";
		cout<<nL;
	}
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}