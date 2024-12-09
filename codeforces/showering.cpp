/** 
 immortalzodd
 07.08.2024 17:54:04
 showering
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

void solve(){
    ll n,s,m; cin>>n>>s>>m;
    bool start=false,mid=false,end=false;

    vector<pii> arr(n);
    for(pii&p:arr) cin>>p.first>>p.second;

    sort(all(arr));
	
	start|=(arr[0].first>=s);

	fr(i,1,n){
		mid|=(arr[i].first-arr[i-1].second>=s);
	}

	end|=(m-arr[n-1].second>=s);

	cout<<(start||mid||end?"YES":"NO")<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}