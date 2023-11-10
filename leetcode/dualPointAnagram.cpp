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
	bool ans=true;
	ll i=0,j=str.size()-1;
	transform(all(str),str.begin(),::tolower);
	for(;i<=j;){
		if(ispunct(str[i])||ispunct(str[j])||str[i]==' '||str[j]==' '){
			if(ispunct(str[i])||str[i]==' ') i++;
			if(ispunct(str[j])||str[j]==' ') j--;
		}
		else if(str[i]==str[j]){
			i++; j--;
		}
		else{
			ans=false;
			break;
		}
	}
	if(str.size()==0) ans=true;
	cout<<(ans==true?"true":"false")<<nL;
}