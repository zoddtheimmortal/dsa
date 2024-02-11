/**
 immortalZodd
 24.01.2024 22:45:53
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

bool cmp(pair<ll,ll> c1,pair<ll,ll> c2){
	return c1.second<c2.second;
}

void solve(){
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
    ll n; cin>>n;
    vector<pair<ll,ll>> arr(n,make_pair(0,0));
    fr(i,0,n){
    	cin>>arr[i].first>>arr[i].second;
    }
    sort(all(arr),cmp);

    ll si=0,ei=n-1,max_time=INT_MIN;
    while(si<=ei){
    	ll pairs=min(arr[si].first,arr[ei].first);
    	if(si==ei) pairs/=2;
    	max_time=max(max_time,arr[si].second+arr[ei].second);
    	arr[si].first-=pairs;
    	arr[ei].first-=pairs;
    	if(arr[si].first==0) si++;
    	if(arr[ei].first==0) ei--;
    }

    cout<<max_time<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}