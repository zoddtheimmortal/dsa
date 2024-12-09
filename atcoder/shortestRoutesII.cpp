/** 
 immortalzodd
 10.06.2024 15:14:13
 shortestRoutesII
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,m,q;
vector<vector<pii>> arr;

void solve(){
    cin>>n>>m>>q;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	--f; --s;
    	arr[f].push_back({s,w});
    	arr[s].push_back({f,w});
    }
    int dist[n][n]={0};
    fr(i,0,n){
    	fr(j,0,n) dist[i][j]=INT_MAX;
    }
    fr(i,0,n) dist[i][i]=0;
    fr(i,0,n){
    	for(pii&x:arr[i]) dist[i][x.first]=x.second;
    }

	fr(i,0,n){
		fr(j,0,n){
			fr(k,0,n){
				if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX) continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	while(q--){
		ll f,s; cin>>f>>s;
		cout<<(dist[--f][--s]>=INT_MAX?-1:dist[f][s])<<nL;
	}
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}