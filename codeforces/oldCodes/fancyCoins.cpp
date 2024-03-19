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
		int m,k,a1,ak; cin>>m>>k>>a1>>ak;
		int maxK=m/k,min1=m%k;
		int extra1=max(0,a1-min1);
		int transfer=extra1/k; maxK-=transfer; min1+=transfer*k;
		int fancyK=max(0,maxK-ak),fancy1=max(0,min1-a1);
		cout<<fancyK+fancy1<<endl;
	}
}

