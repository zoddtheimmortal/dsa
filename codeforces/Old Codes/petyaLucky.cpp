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
	string str; cin>>str;
	bool ans=true;
	ll count=0;
	rep(c,str){
		if(c=='4'||c=='7'){
			count++;
		}
	}
	string check=to_string(count);
	rep(c,check){
		if(c=='4'||c=='7');
		else ans=false;
	}
	cout<<(ans==true?"YES":"NO")<<nL;
}