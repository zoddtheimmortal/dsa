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

bool check(vi arr,ll n,ll q,ll target){
	ll c=0;
	fr(i,0,n){
		if(arr[i]>=q){
			c++;
		}
        if(c==target) return true;
	}
	return false;
}

void solve(){
    ll n,k; cin>>n>>k;
    vi candy(n,0); fr(i,0,n) cin>>candy[i];
    sort(all(candy));
    ll si=1,ei=candy[n-1],ans=0;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(candy,n,mid,k)){
    		ans=mid;
    		si=mid+1;
    	}else{
    		ei=mid-1;
    	}
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
