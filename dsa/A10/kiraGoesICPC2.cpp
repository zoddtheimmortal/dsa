/** 
 immortalzodd
 11.04.2024 12:09:27
 kiraGoesICPC2
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

int ans=0;
vector<vi> arr;

pair<int,int> dfs(int x,int p){
	pair<int,int> pq={1,0};

	for(auto&y:arr[x]){
		if(y!=p){
			auto ptemp=dfs(y,x);
			pq.first+=ptemp.first;
			pq.second+=ptemp.first+ptemp.second;
		}
	}

	ans+=pq.second;
	return pq;
}

void solve(){
    ll n; cin>>n;
    arr.resize(++n);

    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }

    dfs(0,0);
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}