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
	ll chest=0,bicep=0,back=0;
	fr(i,0,n){
		if(i%3==0) chest+=arr[i];
		if(i%3==1) bicep+=arr[i];
		if(i%3==2) back+=arr[i];
	}
	if(chest>bicep && chest>back) cout<<"chest"<<nL;
	if(bicep>chest && bicep>back) cout<<"biceps"<<nL;
	if(back>bicep && back>chest) cout<<"back"<<nL;
}