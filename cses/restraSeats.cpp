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
#define F first
#define S second

bool compare(pair<ll,int> n1,pair<ll,int> n2);

//sweeping line algo

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n; cin>>n;
	n*=2;
	std::vector<pair<ll,int>> arr(n);
	int parity=1; //1->arrival
	fr(i,0,n){
		cin>>arr[i].first;
		arr[i].second=parity;
		parity=(parity==1)?-1:1;
	}
	sort(all(arr),compare);
	ll count=0,ans=0;
	fr(i,0,n){
		count+=arr[i].S;
		ans=max(ans,count);
	}
	cout<<ans<<nL;
}

bool compare(pair<ll,int> n1,pair<ll,int> n2){
	return n1.first<n2.first;
}