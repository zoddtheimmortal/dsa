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

bool markColor(v(vi) arr,int n,int sv,vi &color){
	queue<int> qs;
	qs.push(sv);
	color[sv]=0;

	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(arr[vertex][i]==1 && color[vertex]==color[i]){
				return false;
			}
			if(color[i]==-1 && arr[vertex][i]==1){
				qs.push(i);
				color[i]=1-color[vertex];
			}
		}
	}
	return true;
}

bool isBipartite(v(vi) arr,int n){
	vi color(n,-1);
	bool ans=true;
	fr(i,0,n){
		if(color[i]==-1){
			ans=markColor(arr,n,i,color);
		}
		if(ans==false) return ans;
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
    cout<<(isBipartite(arr,n)?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}