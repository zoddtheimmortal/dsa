#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define nL "\n"

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,c; cin>>n>>c;
		vl arr(n);
		ll b=0,k=0;
		rep(i,0,n){
			cin>>arr[i];
			b+=(arr[i]); k+=(arr[i]*arr[i]);
		}
		k-=c;
		ll ans1,ans2;
		ans1=(ll)((2*sqrtl(b*b-(n*c))/(n))-(b/(2*n)));
		ans2=(ll)(((-1)*(2*sqrtl(b*b-(n*c))/(n)))-(b/(2*n)));
		cout<<ans1<<" "<<ans2<<endl;
	}
}

