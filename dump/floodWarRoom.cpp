/** 
 immortalzodd
 05.08.2024 11:04:58
 floodWarRoom
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

ll n,q;
vector<vi> arr;

const int BIG=1e9;

int bfs(int s,int d){
	vi dist(n,BIG);
	dist[s]=0;

	queue<ll> qs;
	qs.push(s);

	while(!qs.empty()){
		ll v=qs.front();
		qs.pop();

		if(v==d) return dist[d];

		for(int&u:arr[v]){
			if(dist[u]==BIG){
				dist[u]=1+dist[v];
				qs.push(u);
			}
		}
	}
	return 9999;
}

void solve(){
    cin>>n>>q;
    arr.resize(n);
    fr(i,0,n){
    	fr(j,0,n){
    		int x; cin>>x;
    		if(x==1) arr[i].push_back(j);
    	}
    }

    fr(i,0,q){
    	int x,y; cin>>x>>y;
    	cout<<bfs(x,y)<<nL;
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