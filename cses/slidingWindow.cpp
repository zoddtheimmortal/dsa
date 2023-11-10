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

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n,k; cin>>n>>k;
	vl arr(n); fr(i,0,n) cin>>arr[i];
	fr(i,0,n-k+1){
		vl temp(k);
		partial_sort_copy(arr.begin()+i,arr.begin()+i+k,all(temp));
		ll mid=temp[(k/2)];
		ll count=0;
		fr(j,0,k){
			count+=abs(temp[j]-mid);
		}
		cout<<count<<" ";
	}
	cout<<nL;
}