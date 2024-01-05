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

int markBanana(v(vi) arr,int n,int sv,vi banan,v(bool) &visited){
	int cost=0;
	queue<int> qs;

	visited[sv]=true;
	qs.push(sv);
	cost+=banan[sv];

	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				qs.push(i);
				visited[i]=true;
				cost+=banan[i];
			}
		}
	}
	return cost;
}

int maxBanan(v(vi) arr,int n,vi banan){
	v(bool) visited(n,false);
	int ans=0,temp=0;
	fr(i,0,n){
		if(!visited[i]){
			temp=markBanana(arr,n,i,banan,visited);
			ans=max(temp,ans);
		}
	}
	return ans;
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
	vi banan(n,0);
	fr(i,0,n) cin>>banan[i];
	cout<<maxBanan(arr,n,banan)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}