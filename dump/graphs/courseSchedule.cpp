/** 
 immortalzodd
 29.06.2024 11:05:41
 courseSchedule
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
    	for(int&x:arr[i]) indeg[x]++;
    }

	queue<int> qs;
	fr(i,0,n) if(indeg[i]==0) qs.push(i);
	vi topsort;

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		topsort.push_back(v);
		for(int&u:arr[v]){
			if(--indeg[u]==0) qs.push(u);
		}
	}
	if(topsort.size()<n) cout<<"IMPOSSIBLE"<<nL;
	else{
		for(int&x:topsort) cout<<x+1<<" ";
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