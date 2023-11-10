#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

bool compare(pair<ll,ll> n1,pair<ll,ll> n2);

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	vector<pair<ll,ll>> arr(n); fr(i,0,n) cin>>arr[i].first>>arr[i].second;
	sort(all(arr),compare);
	ll count=1,temp=arr[0].second;
	fr(i,1,n){
		if(arr[i].first>=temp){
			count++;
			temp=arr[i].second;
		}
	}
	cout<<count<<nL;
}

bool compare(pair<ll,ll> n1,pair<ll,ll> n2){
	return n1.second<n2.second;
}