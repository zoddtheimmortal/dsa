/**
 immortalZodd
 24.01.2024 11:47:25
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for(ll i = a; i < (b); ++i)
#define rf(i, a, b) for(ll i = b; i >=(a); i--)
#define nL "\n"

void solve(){
    ll n,q; cin>>n>>q;
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i].first;
    	arr[i].second=i;
    }
    sort(all(arr));
	fr(i,0,n){
		ll x=arr[i].first;
		ll si=i+1,ei=n-1;
		while(si<ei){
			if(arr[si].first+arr[ei].first==q-x){
				cout<<arr[si].second+1<<" "<<arr[ei].second+1<<" "<<arr[i].second+1<<nL;
				return;
			}
			else if(arr[si].first+arr[ei].first<q-x){
				si++;
			}
			else ei--;
		}
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