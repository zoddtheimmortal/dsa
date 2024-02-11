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

bool cmp(pair<ll,ll> a1,pair<ll,ll> a2){
	return a1.first<a2.first;
}

void solve(){
	ll n,k; cin>>n>>k;
	vector<pair<ll,ll>> arr(n);
	fr(i,0,n){
		cin>>arr[i].first;
		arr[i].second=i;
	}

	sort(all(arr),cmp);

	ll si=0,ei=n-1;
	while(si<ei){
		if(arr[si].first+arr[ei].first==k){
			cout<<arr[si].second+1<<" "<<arr[ei].second+1<<nL;
			return;
		}
		else if(arr[si].first+arr[ei].first<k) si++;
		else ei--;
	}
	cout<<"IMPOSSIBLE"<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}