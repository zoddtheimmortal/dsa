/** 
 immortalzodd
 02.06.2024 00:30:51
 studentsAndShoelaces
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
vi deg;

void solve(){
    cin>>n>>m;
    arr.resize(n);
    deg.assign(n,0);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    	deg[f]++; deg[s]++;
    }
    int ans=0,size=1,nodes[101];
    while(size>0){
    	size=0;
    	fr(i,0,n){
    		if(deg[i]==1){
    			deg[i]--;
    			nodes[size++]=i;
    		}
    	}
    	fr(i,0,size){
    		for(int&y:arr[nodes[i]]) deg[y]--;
    	}
    	ans++;
    }
    cout<<ans-1<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}