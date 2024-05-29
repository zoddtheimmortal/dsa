/** 
 immortalzodd
 11.04.2024 15:27:43
 disco,dsa,daa
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

void solve(){
    ll n,m; cin>>n>>m;
    vector<vi> arr(n);

    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    }

    vi indeg(n,0);
    fr(i,0,n){
    	for(int&x:arr[i]) indeg[x]++;
    }

	queue<int> qs;
	vi ans;
	fr(i,0,n){
		if(indeg[i]==0) qs.push(i);
	}

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		ans.push_back(v+1);
		for(auto&x:arr[v]){
			indeg[x]--;
			if(indeg[x]==0) qs.push(x);
		}
	}

	if(ans.size()!=n){
		cout<<"IMPOSSIBLE"<<nL;
	}
	else{
		for(auto&x:ans) cout<<x<<" ";
		cout<<nL;
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}