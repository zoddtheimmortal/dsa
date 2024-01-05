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

int shortPath(v(vi) arr,int n,int sv,int ev){
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
				visited[i]=true;
				qs.push(i);
				mp[i]=vertex;
				if(i==ev){
					flag=true;
					break;
				}
			}
		}
		if(flag) break;
	}

	int k=ev,len=0;
	while(k!=sv){
		len++;
		k=mp[k];
	}
	return len;
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
    cout<<shortPath(arr,n,sv,ev)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}