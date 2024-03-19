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
	int n; cin>>n;
	vi arr(n); fr(i,0,n) cin>>arr[i];
	int swaps=0,temp=0;
	vi::iterator max=max_element(all(arr));
	temp=*(max);
	swaps+=(max-arr.begin());
	arr.erase(max);
	arr.insert(arr.begin(),temp);

	vi::iterator min=min_element(all(arr));
	vi::iterator it=min;\
	temp=*min;
	for(;it!=arr.end();it++){
		if(*it==*min) min=it;
	}
	swaps+=(arr.end()-min)-1;

	cout<<swaps<<nL;
}

