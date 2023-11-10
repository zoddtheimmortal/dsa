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
		ll l,r; cin>>l>>r;
		bool ans=true;
		ll a=0,b=0;
		if(l==r){
			ll div=1;
			for(ll i=2;i<(sqrt(l)+1);i++){
				if(l%i==0){
					div=i;
				}
			}
			if(div==1) ans=false;
			a=div; b=l-div;
		}
		else a=b=r/2;

		if(r<=3) ans=false;

		if(ans==false) cout<<-1<<nL;
		else cout<<a<<" "<<b<<nL;

	}
}