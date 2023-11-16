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

ll len=0;
void markPath(v(vi) arr,int n,int sv,int ev){
	v(bool) visited(n,false);
	queue<int> qs;
	unordered_map<int,int> mp;
	qs.push(sv);
	visited[sv]=true;
	bool flag=false;
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				mp[i]=vertex;
				qs.push(i);
				visited[i]=true;
			}
			if(vertex==ev){
				flag=true;
				break;
			}
		}
		if(flag) break;
	}
	int k=ev;
	while(k!=sv){
		len++;
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
    int sv=0,ev=n-1;
    markPath(arr,n,sv,ev);
    cout<<len<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}