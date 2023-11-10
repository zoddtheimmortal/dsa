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

bool check(vi arr,int n,int c,int k){
	ll last=arr[0],count=1;
	fr(i,0,n){
		if(arr[i]-last>=k){
			count++;
			last=arr[i];
		}
		if(count==c) return true;
	}
	return false;
}

void solve(){
     ll n,c; cin>>n>>c;
     vi arr(n,0),diff(n-1,0);
     fr(i,0,n) cin>>arr[i];
     sort(all(arr));
     
     ll si=0,ei=arr[n-1]-arr[0],ans=0;
     while(si<=ei){
     	ll mid=si+(ei-si)/2;
     	if(check(arr,n,c,mid)){
     		ans=mid;
     		si=mid+1;
     	}
     	else ei=mid-1;
     }
     cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}