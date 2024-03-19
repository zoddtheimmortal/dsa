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
	string i1,i2,f1; cin>>i1>>i2>>f1;
	string op=i1+i2;

	sort(all(op)); sort(all(f1));
	bool ans=true;
	if(op.size()!=f1.size()) ans=false;

	fr(i,0,(min(op.size(),f1.size()))){
		if(op[i]!=f1[i]){
			ans=false;
			break;
		}
	}

	cout<<(ans==true?"YES":"NO")<<nL;
}