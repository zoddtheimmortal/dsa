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
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin>>n>>k;
	vi arr(n); fr(i,0,n) arr[i]=(i+1);
	vector<vector<int>> ans;
	fr(i,1,n){
		vi temp={i,0};
		fr(j,i+1,n){
			temp[1]=j;
			ans.pb(temp);
		}
	}
	cout<<ans.size()<<nL;
}