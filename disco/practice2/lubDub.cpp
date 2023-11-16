#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

using ll=long long;
using vi=vector<int>;

#define pb push_back
#define all(x) x.begin(),x.end()
#define v(x) vector<x>
#define rep(it,arr) for(auto it:arr)
#define nL endl

void markBFS(v(vi) arr,int n,int sv,vi &path){
	queue<int> qs;
	v(bool) visited(n,false);
	qs.push(sv);
	visited[sv]=true;
	path.pb(sv);

	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		for(int i=0;i<n;i++){
			if(!visited[i] && arr[vertex][i]==1){
				qs.push(i);
				visited[i]=true;
				path.pb(i);
			}
		}
	}
}

int getMatch(vi arr,vi brr){
	rep(it,arr){
		rep(jt,brr){
			if(it==jt) return it;
		}
	}
	return -1;
}


void solve(){
	ll n,e,sx,sy; cin>>n>>e>>sx>>sy;
	v(vi) lb(n,vi(n,0)),gb(n,vi(n,0));
	for(int i=0;i<e;i++){
		ll f,s;
		cin>>f>>s;
		lb[f-1][s-1]=1;
		gb[s-1][f-1]=1;
	}
	vi a1,a2,b1,b2;
	markBFS(lb,n,sx-1,a1);
	markBFS(lb,n,sy-1,a2);

	markBFS(gb,n,sx-1,b1);
	markBFS(gb,n,sy-1,b2);

	int lub=getMatch(a1,a2),gub=(getMatch(b1,b2));

	cout<<gub+1<<" "<<lub+1<<nL;
}

int main(){
	ll t=1;
	while(t--){
		solve();
	}
}