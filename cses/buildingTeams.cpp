/** 
 immortalZodd
 02.02.2024 22:45:12
 buildingTeams
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

bool mark_color(vi arr[],ll n,ll sv,vi &color){
	queue<ll> qs;
	color[sv]=0;
	qs.push(sv);

	while(!qs.empty()){
		ll vertex=qs.front(); qs.pop();

		for(auto &x:arr[vertex]){
			if(color[x]==-1){
				color[x]=1-color[vertex];
				qs.push(x);
			}
			else if(color[x]==color[vertex]) return false;
		}
	}
	return true;
}

void colorTeams(vi arr[],ll n){
	vi color(n,-1);
	bool poss=true;

	fr(i,0,n){
		if(color[i]==-1){
			poss=mark_color(arr,n,i,color);
		}
		if(!poss){
			cout<<"IMPOSSIBLE"<<nL;
			return;
		}
	}

	fr(i,0,n){
		cout<<color[i]+1<<" ";
	}
	cout<<nL;
}

void solve(){
    ll n,m; cin>>n>>m;
    vi arr[n];
    while(m--){
    	ll f,s; cin>>f>>s;
    	arr[f-1].push_back(s-1);
    	arr[s-1].push_back(f-1);
    }
    colorTeams(arr,n);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}