#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

vi path;
void markPath(v(vi) arr,int n,vi &indeg){
	queue<int> qs;
	v(bool) visited(n,false);
	fr(i,0,n){
		if(indeg[i]==0){
			qs.push(i);
			visited[i]=true;
			path.pb(i);
		}
	}

	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				indeg[i]-=1;
				if(indeg[i]==0){
					qs.push(i);
					visited[i]=true;
					path.pb(i);
				}
			}
		}
	}
}

void solve(){
    ll n; cin>>n;
    v(vi) arr(n,vi(n,0));
    vi indeg(n,0);
    fr(i,0,n){
    	int x; cin>>x;
    	indeg[i]=x;
    	fr(k,0,x){
    		ll s; cin>>s;
    		arr[s-1][i]=1;
    	}
    } 
    markPath(arr,n,indeg);

    if(path.size()==n){
    	rep(it,path) cout<<it+1<<" ";
    }
    else cout<<-1;
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}