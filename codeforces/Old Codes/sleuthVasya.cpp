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
	string str; getline(cin,str);
	bool ans=false;
	str.erase(remove(all(str),' '),str.end());
	str.erase(remove(all(str),'?'),str.end());
	transform(all(str),str.begin(),::tolower);
	int n=str.size()-1;
	if(str[n]=='a'||str[n]=='e'||str[n]=='i'||
		str[n]=='o'||str[n]=='u'||str[n]=='y') ans=true;
	cout<<(ans==true?"YES":"NO")<<nL;
}