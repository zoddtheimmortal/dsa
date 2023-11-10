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
		int n,ans=0; cin>>n;
		string str; cin>>str;
		vi indices;
		fr(i,0,n){
			if(str[i]=='1') indices.pb(i);
		}
		ll adj=0;
		fr(i,1,indices.size()){
			if((abs(indices[i]-indices[i-1]))==1) adj++;
		}
		if(indices.size()==0) ans=0;
		else if(adj==0) ans=1;
		else ans=2;
		cout<<ans<<nL;
	}
}