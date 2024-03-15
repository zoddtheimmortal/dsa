/** 
 immortalzodd
 01.03.2024 21:03:27
 wormholeSort
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

ll n,m;

bool check(vi arr,vector<vi> hole,ll tshld){
	fr(k,0,m){
		int i=hole[k][0]-1,j=hole[k][1]-1,width=hole[k][2];
		if(width>=tshld &&i<j&&arr[i]>arr[j]) swap(arr[i],arr[j]);
		else if(width>=tshld &&i>j&&arr[i]<arr[j]) swap(arr[i],arr[j]);
	}
	fr(i,1,n) if(arr[i-1]>arr[i]) return false;
	return true;
}

void solve(){
	cin>>n>>m;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    vector<vi> hole(m,vi(3,0)); 
    fr(i,0,m){
    	fr(j,0,3) cin>>hole[i][j];
    }

	ll si=-1,ei=1e9,ans=-3;
	while(si<=ei){
		ll mid=si+(ei-si)/2;
		if(check(arr,hole,mid)){
			ans=mid;
			ei=mid-1;
		}else si=mid+1;
	}
	cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}