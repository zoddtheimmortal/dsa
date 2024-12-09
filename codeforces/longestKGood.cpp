/** 
 immortalzodd
 20.07.2024 22:44:28
 longestKGood
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
    ll n,k; cin>>n>>k;
    vi arr(n); for(int&x:arr) cin>>x;

    ll si=0,ei=0,l=0,r=0,mlen=0;
    map<ll,ll> mp;

    while(ei<n){
    	mp[arr[ei]]++;
    	while(si<=ei&&mp.size()>k){
    		mp[arr[si]]--;
    		if(mp[arr[si]]==0) mp.erase(arr[si]);
    		si++;
    	}
    	if(mlen<ei-si+1){
    		mlen=ei-si+1;
    		l=si;
    		r=ei;
    	}
    	ei++;
    }
    cout<<++l<<" "<<++r<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}