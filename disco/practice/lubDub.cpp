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

void markDFS(v(vi) arr,int n,int sv,v(bool) &visited,vi &path){
	visited[sv]=true;
	path.pb(sv);
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			markDFS(arr,n,i,visited,path);
		}
	}
}

void markBFS(v(vi) arr,int n,int sv,vi &path){
	queue<int> qs;
	v(bool) visited(n,false);
	qs.push(sv);
	visited[sv]=true;
	path.pb(sv);
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				qs.push(i);
				visited[i]=true;
				path.pb(i);
			}
		}
	}
}

int findCommon(vi arr,vi brr){
	rep(it,arr){
		rep(jt,brr){
			if(it==jt) return it;
		}
	}
	return -1;
}

void solve(){
    ll n,e,sv,ev; cin>>n>>e>>sv>>ev;
    v(vi) gb(n,vi(n,0)),lb(n,vi(n,0));
    fr(i,0,e){
    	ll f,s;
    	cin>>f>>s;
    	gb[f-1][s-1]=1;
    	lb[s-1][f-1]=1;
    } 
    vi a1,a2,b1,b2;
    markBFS(gb,n,sv-1,a1);
    markBFS(gb,n,ev-1,a2);
    markBFS(lb,n,sv-1,b1);
    markBFS(lb,n,ev-1,b2);

    int gub=findCommon(a1,a2),lub=findCommon(b1,b2);
    cout<<lub+1<<" "<<gub+1<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}