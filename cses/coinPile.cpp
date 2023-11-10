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
#define fr(i, a, b) for (int i = a; i < (b); ++i)
#define rf(i, a, b) for (int i = b; i >=(a); i--)
#define nL "\n"

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		bool ans=false;
		ll x1=((2*b)-a)/3,x2=((2*a)-b)/3;
		if(((2*x1)+x2)==b && ((2*x2)+x1)==a) ans=true;
		if(((a==0)^(b==0))||(max(a,b)>2*min(a,b))) ans=false;
		// cout<<(2*x1+x2)<<" "<<(2*x2+x1)<<nL;
		cout<<(ans==true?"YES":"NO")<<nL;
	}
}