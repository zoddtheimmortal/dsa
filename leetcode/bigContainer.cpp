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
	vi arr(n); fr(i,0,n) cin>>arr[i];
	int areaMax=0,si=0,ei=arr.size()-1;
	while(si<=ei){
		int width=ei-si;
		areaMax=max(areaMax,(min(arr[si],arr[ei])*width));
		if(arr[si]<arr[ei]){
			si++;
		}
		else{
			ei--;
		}
	}
	cout<<areaMax<<nL;
}