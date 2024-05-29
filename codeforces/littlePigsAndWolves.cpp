/** 
 immortalzodd
 26.05.2024 23:01:45
 littlePigsAndWolves
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

void solve(){
    ll n,m; cin>>n>>m;
    vector<string> arr(n);
    for(string&s:arr) cin>>s;
    int ans=0;
	vi dx={-1,0,1,0}; vi dy={0,-1,0,1};
	fr(i,0,n){
		fr(j,0,m){
			if(arr[i][j]=='W'){
				int pigs=0;
				fr(k,0,4){
					if(i+dx[k]>=0&&j+dy[k]>=0&&i+dx[k]<n&&j+dy[k]<m&&
						arr[i+dx[k]][j+dy[k]]=='P') pigs=max(pigs,1);
				}
				ans+=pigs;
			}
		}
	}
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}