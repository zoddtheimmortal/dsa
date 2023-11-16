#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using namespace std;

using ll=long long;
using vi=vector<int>;

#define pb push_back
#define fr(i,x,y) for(int i=x;i<y;i++)
#define rep(it,arr) for(auto it:arr)
#define v(x) vector<x>
#define nL endl

int path;
int shortestPath(v(vi) arr,int n,int sv,int ev){
	queue<int> qs;
	v(bool) visited(n,false);
	unordered_map<int,int> mp;
	qs.push(sv);
	visited[sv]=true;
	mp[sv]=sv;
	bool flag=false;
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				qs.push(i);
				visited[i]=true;
				mp[i]=vertex;
				if(i==ev){
					flag=true;
					break;
				}
			}
		}
		if(flag) break;
	}

	int k=ev;
	while(k!=sv){
		path++;
		k=mp[k];
	}
}

void solve(){
	ll n,e; cin>>n>>e;
	v(vi) arr(n,vi(n,0));
	fr(i,0,e){
		ll f,s;
		cin>>f>>s;
		arr[f-1][s-1]=1;
		arr[s-1][f-1]=1;
	}
	ll sv=0,ev=n-1;
	shortestPath(arr,n,sv,ev);
	cout<<path<<nL;
}

int main(){
	ll t=1;
	while(t--){
		solve();
	}
}