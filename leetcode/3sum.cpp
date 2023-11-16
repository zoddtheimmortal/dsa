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

v(vi) threeSum(vi arr,int n){
	ll target=0;
	sort(all(arr));
	v(vi) triplets;
	fr(i,0,n){
		ll si=i+1,ei=n-1,sum=target-arr[i];
		while(si<ei){
			if(arr[si]+arr[ei]==sum){
				bool flag=false;
				fr(i,0,triplets.size()){
					if(triplets[i][0]==arr[i] && triplets[i][1]==arr[si] && triplets[i][2]==arr[ei]) flag=true;
				}
				if(!flag) triplets.pb({arr[i],arr[si],arr[ei]});
			}
			else if(arr[si]+arr[ei]<sum) si++;
			else ei--;
		}
	}
	return triplets;
}

void solve(){
    ll n; cin>>n;
    vi arr(n,0);
    fr(i,0,n) cin>>arr[i];
    v(vi) triplets=threeSum(arr,n);
    rep(it,triplets){
    	rep(jt,it) cout<<jt<<" ";
    	cout<<nL;
    }  
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}