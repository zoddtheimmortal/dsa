/** 
 immortalzodd
 04.07.2024 10:13:30
 courseScheduleIV
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

using pii = pair<int,int>;
vector<vi> arr;
vi topsort(){
	int n=arr.size();
	vi indeg(n,0),parent(n,-1);
	for(int i=0;i<n;i++){
		for(int&x:arr[i]) indeg[x]++;
	}
queue<int> qs;
for(int i=0;i<n;i++) if(indeg[i]==0) qs.push(i);

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		for(int&u:arr[v]){
			if(--indeg[u]==0){
				qs.push(u);
				parent[u]=v;
			}
		}
	}
	return parent;
}

vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
	arr.resize(n);
	for(vi&v:pre){
		arr[v[1]].push_back(v[0]);
	}
	vi parent=topsort();
	for(int&p:parent) cout<<p<<" ";
	cout<<nL;
	int m=q.size();
	vector<bool> ans(m);
	for(int i=0;i<m;i++){
		int it=q[i][0];
		while(it!=q[i][1]&&it!=-1){
			it=parent[it];
		}
		ans[i]=(it==q[i][1]);
	}
	return ans;
}

void solve(){
	int n,m,q; cin>>n>>m>>q;
	vector<vi> pre(m),query(q);
	fr(i,0,m){
		int x,y; cin>>x>>y;
		pre[i]={x,y};
	}
	fr(i,0,q){
		int x,y; cin>>x>>y;
		query[i]={x,y};
	}
	vector<bool> ans=checkIfPrerequisite(n,pre,query);
	for(bool b:ans) cout<<b<<" ";
	cout<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}