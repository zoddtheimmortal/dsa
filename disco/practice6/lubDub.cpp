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

void markBFS(v(vi) arr,int n,int v,vi &path){
	queue<int> qs;
	v(bool) visited(n,false);

	qs.push(v);
	visited[v]=true;
	path.pb(v);

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

int checkMatch(vi arr,vi brr){
	rep(it,arr){
		rep(jt,brr){
			if(it==jt) return it+1;
		}
	}
	return -1;
}

void solve(){
    ll n,e,x,y; cin>>n>>e>>x>>y;
    v(vi) lb(n,vi(n,0)),gb(n,vi(n,0));
    fr(i,0,e){
    	ll f,s;
    	cin>>f>>s;
    	lb[f-1][s-1]=1;
    	gb[s-1][f-1]=1;
    } 
    vi a1,a2,b1,b2;
    markBFS(lb,n,x-1,a1);
    markBFS(lb,n,y-1,a2);

    markBFS(gb,n,x-1,b1);
    markBFS(gb,n,y-1,b2);

    int lub=checkMatch(a1,a2),glb=checkMatch(b1,b2);

    cout<<glb<<" "<<lub<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}