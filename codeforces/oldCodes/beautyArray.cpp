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
#define fr(i, a, b) for (int i = a; i < (b); ++i)
#define rf(i, a, b) for (int i = b; i >=(a); i--)
#define nL "\n"

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		ll secSum=0,min=INT_MAX,secMin=INT_MAX;
		while(n--){
			int m; cin>>m;
			vi arr(m); fr(i,0,m) cin>>arr[i];
			sort(all(arr));
			secSum+=(arr[1]);
			if(arr[0]<min) min=arr[0];
			if(arr[1]<secMin) secMin=arr[1];
		}
		cout<<min+secSum-secMin<<nL;
	}
}

