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

const ll BIG=1e18;

void solve(){
	ll n,m,q; cin>>n>>m>>q;
	vector<vl> arr(n,vl(n,BIG));

	fr(i,0,m){
		ll f,s,w; cin>>f>>s>>w;
		--f; --s;
		arr[f][s]=min(arr[f][s],w);
		arr[s][f]=min(arr[s][f],w);
	}

	fr(k,0,n){
		fr(i,0,n){
			fr(j,0,n){
				if(i==j) arr[i][j]=0;
				else{
					arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
				}
			}
		}
	}

	fr(i,0,q){
		ll f,s; cin>>f>>s;
		cout<<(arr[--f][--s]>=BIG?-1:arr[f][s])<<nL;
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