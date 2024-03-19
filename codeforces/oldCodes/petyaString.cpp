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
	string str1,str2; cin>>str1>>str2;
	transform(all(str1),str1.begin(),::tolower);
	transform(all(str2),str2.begin(),::tolower);
	ll ans=0,n=str1.size();
	fr(i,0,n){
		if(str1[i]!=str2[i]){
			ans=str1[i]-str2[i];
			break;
		}
	}
	cout<<(ans>0?1:(ans<0?-1:0))<<nL;
}