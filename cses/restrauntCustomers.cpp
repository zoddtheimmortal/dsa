/**
 immortalZodd
 21.01.2024 09:36:01
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

void solve(){
	ll n; cin>>n;
    vector<pair<ll,ll>> arr(2*n);
    for(int i=0;i<2*n;i+=2){
    	ll in,out; cin>>in>>out;
    	arr[i]=make_pair(in,0);
    	arr[i+1]=make_pair(out,1);
    }
    sort(all(arr));
    ll ans=0,cnt=0;
    fr(i,0,2*n){
    	if(arr[i].second==0) cnt++;
    	else cnt--;
    	ans=max(ans,cnt);
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