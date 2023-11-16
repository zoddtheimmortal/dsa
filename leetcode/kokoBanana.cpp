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

void solve(){
    ll n,h; cin>>n>>h;
    vi arr(n,0);
    fr(i,0,n) cin>>arr[i];
    sort(all(arr));
    int si=1,ei=arr[n-1],ans=arr[n-1];
    while(si<=ei){
    	int mid=si+(ei-si)/2,temp=0;
    	fr(i,0,n){
    		if(arr[i]%mid==0) temp+=arr[i]/mid;
    		else temp+=arr[i]/mid+1;
    	}
    	if(temp<=h){
    		ei=mid-1;
    		ans=mid;
    	}
    	else si=mid+1;
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