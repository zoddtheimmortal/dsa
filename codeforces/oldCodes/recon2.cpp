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
	int n; cin>>n;
	vi arr(n); fr(i,0,n) cin>>arr[i];
	pair<int,int> ans;
	ll temp=INT_MAX;
	fr(i,1,n){
		if(temp>(abs(arr[i]-arr[i-1]))){
			temp=abs(arr[i]-arr[i-1]);
			ans.first=i;
			ans.second=i+1;
		}
	}
	if(abs(arr[0]-arr[n-1])<temp){
		temp=abs(arr[0]-arr[n-1]);
		ans.first=1;
		ans.second=n;
	}
	cout<<ans.first<<" "<<ans.second<<nL;
}