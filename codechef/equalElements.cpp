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
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vi arr(n); fr(i,0,n) cin>>arr[i];
		sort(all(arr));
		ll ans=1,temp=1;
		fr(i,0,n-1){
			if(arr[i]==arr[i+1]) temp++;
			else temp=1;

			ans=max(ans,temp);
		}
		cout<<n-ans<<nL;
	}
}