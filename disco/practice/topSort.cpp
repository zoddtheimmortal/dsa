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
void topSort(v(vi) arr,int n,vi &indeg){
	v(bool) visited(n,false);
	queue<int> qs;
	fr(i,0,n){
		if(indeg[i]==0){
			qs.push(i);
			path.pb(i);
			visited[i]=true;
		}
	}
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				indeg[i]-=1;
				if(indeg[i]==0){
					visited[i]=true;
					qs.push(i);
					path.pb(i);
				}
			}
		}
	}
}

void solve(){
    ll n; cin>>n;
    vi indeg(n,0);
    v(vi) arr(n,vi(n,0));
    fr(i,0,n){
    	int deg; cin>>deg;
    	indeg[i]=deg;
    	fr(j,0,deg){
    		ll s; cin>>s;
    		arr[s-1][i]=1;
    	}
    } 
    topSort(arr,n,indeg);
    bool sorted=true;
    fr(i,0,n){
    	if(indeg[i]>0){
    		sorted=false;
    		break;
    	}
    }
    if(!sorted) cout<<-1;
    else{
    	rep(it,path) cout<<it+1<<" ";
    }
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