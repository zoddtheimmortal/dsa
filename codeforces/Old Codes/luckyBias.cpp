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
	int n,k; cin>>n>>k;
	vector<string> arr(n); fr(i,0,n) cin>>arr[i];
	ll count=0,lucky=0;
	fr(i,0,n){
		lucky=0;
		string temp=arr[i];
		fr(j,0,temp.size()){
			if(temp[j]=='4' || temp[j]=='7') lucky++;
		}
		if(lucky<=k){
			count++;
		}
	}
	cout<<count<<nL;
}