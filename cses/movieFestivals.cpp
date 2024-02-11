/** 
 immortalZodd
 25.01.2024 21:53:45
 movieFestivals
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

bool cmp(pair<ll,ll> a1,pair<ll,ll> a2){
	return a1.second<a2.second;
}

void solve(){
    ll n; cin>>n;
    vector<pair<ll,ll>> arr(n);
    fr(i,0,n){
    	cin>>arr[i].first>>arr[i].second;
    }
    sort(all(arr),cmp);
    ll ans=0,prev_end=-1;
    fr(i,0,n){
    	if(arr[i].first>=prev_end){
    		ans++;
    		prev_end=arr[i].second;
    	}
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