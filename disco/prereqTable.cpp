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
void topSort(v(vi) arr,int n,vi indig){
	queue<int> qs;
	v(bool) visited(n,false);
	fr(i,0,n){
		if(indig[i]==0){
			qs.push(i);
			visited[i]=true;
		}
	}
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		path.pb(vertex);
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]){
				indig[i]-=1;
				if(indig[i]==0){
					qs.push(i);
					visited[i]=true;
				}
			}
		}
	}
}

void solve(){
    ll n; cin>>n;
    v(vi) arr(n,vi(n,0));
    vi indig(n,0);
    fr(i,0,n){
    	ll e; cin>>e;
    	indig[i]=e;
    	fr(j,0,e){
    		ll s; cin>>s;
    		arr[s-1][i]=1;
    	}
    }
    topSort(arr,n,indig);
    if(!path.empty()){
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