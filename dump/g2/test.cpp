#include<bits/stdc++.h>
using namespace std;

const long long BIG=1e18;
long long n,m;
vector<vector<pair<long long,long long>>> arr;
vector<vector<pair<long long,long long>>> revarr;
vector<tuple<long long,long long,long long>> edges;

vector<long long> djikstra(long long s,vector<vector<pair<long long,long long>>>& arr){
	vector<long long> dist(n,BIG);
	dist[s]=0;
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
	pq.push({0,s});

	while(!pq.empty()){
		auto[cdist,v]=pq.top();
		pq.pop();

		if(cdist>dist[v]) continue;
		for(auto[u,cost]:arr[v]){
			if(dist[u]>cdist+cost){
				dist[u]=cdist+cost;
				pq.push({dist[u],u});
			}
		}
}

return dist;
}

int main(){
	cin>>n>>m;
	arr.resize(n);
	revarr.resize(n);
	edges.resize(m);

	for(int i=0;i<m;i++){
		long long f,s,w; cin>>f>>s>>w;
		--f; --s;
		arr[f].push_back({s,w});
		revarr[s].push_back({f,w});
		edges.push_back({f,s,w});
	}
	
	vector<long long> d1=djikstra(0,arr);
	vector<long long> d2=djikstra(n-1,revarr);

	long long ans=INT64_MAX;
	for(auto [u,v,w]:edges){
		long long curcost=d1[u]+w/2+d2[v];
		ans=min(ans,curcost);
	}
	cout<<ans<<"\n";
}