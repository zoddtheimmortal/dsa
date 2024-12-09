/** 
 immortalzodd
 26.06.2024 20:21:05
 interestingDrink
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

ll n;
vi arr;

void search(ll cost){
	int si=0,ei=n-1;
	int ans=-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(arr[mid]<=cost){
			ans=mid;
			si=mid+1;
		}else ei=mid-1;
	}
	cout<<ans+1<<nL;
}

void solve(){
    cin>>n;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    sort(all(arr));

    ll q; cin>>q;
    while(q--){
    	ll m; cin>>m;
    	search(m);
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