#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

vi path;
void findPathBFS(vector<vi> arr,int n,int sv,int ev){
	queue<int> qs;
	vector<bool> visited(n,false);
	qs.push(sv);
	visited[sv]=true;
	unordered_map<int,int> mp;
	bool flag=false;
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				mp[i]=vertex;
				qs.push(i);
				visited[i]=true;
				if(i==ev){
					path.pb(ev);
					flag=true;
					break;
				}
			}
		}
		if(flag) break;
	}
	if(flag){
		int prev=path[0];
		while(prev!=sv){
			path.pb(mp[prev]);
			prev=mp[prev];
		}
	}
	else return;
}

void solve(){
    ll n,e; cin>>n>>e;
    vector<vi> arr(n,vi(n,0));
    fr(i,0,e){
    	ll f,s;
    	cin>>f>>s;
    	arr[f][s]=1;
    	arr[s][f]=1;
    }
    ll sv,ev; cin>>sv>>ev;
    findPathBFS(arr,n,sv,ev);
    if(path.empty());
    else{
    	rep(it,path) cout<<it<<" ";
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