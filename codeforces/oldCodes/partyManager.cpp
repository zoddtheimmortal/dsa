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

int topSort(v(vi) arr,int n,vi indeg){
	v(bool) visited(n,false);
	vi path;
	queue<int> qs;
	int count=0;

	fr(i,0,n){
		if(indeg[i]==0){
			qs.push(i);
			visited[i]=true;
			path.pb(i);
			if(count==0) count=1;
		}
	}

	while(!qs.empty() && path.size()!=n){
		int vertex=qs.front();
		qs.pop();
		count++;
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
	return count;
}

void solve(){
    ll n; cin>>n;
    v(vi) arr(n,vi(n,0));
    vi indeg(n,0);
    fr(i,0,n){
    	ll s; cin>>s;
    	if(s==-1) continue;
    	else{
    		arr[i][s-1]=1;
    		indeg[s-1]++;
    	}
    } 
    cout<<topSort(arr,n,indeg)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}