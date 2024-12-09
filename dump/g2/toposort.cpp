/** 
 immortalzodd
 18.08.2024 21:18:34
 toposort
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

vi toposort(vector<vi> arr,int n){
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

	if(topsort.size()<n) return {-1};
	return topsort;
}

void solve(){
    
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}