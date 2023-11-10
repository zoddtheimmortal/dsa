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
	ll n; cin>>n;
	vl arr(n); fr(i,0,n) cin>>arr[i];
	ll temp=1,seq=arr[0],maxLen=1;
	fr(i,0,n-1){
		if(seq^arr[i+1]!=0){
			temp++;
			seq=seq^arr[i+1];
		}
		else{
			seq=arr[i+1];
			temp=1;
		}
		maxLen=max(maxLen,temp);
	}
	cout<<maxLen-1<<nL;
}