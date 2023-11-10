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
#define nL "\n"

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string str; cin>>str;
	unordered_map<char,ll> map;
	fr(i,0,str.size()){
		map[str[i]]++;
	}
	string temp1="",mid="",op="",temp2="";
	for(auto it:map){
		if((it.second)%2!=0) mid=mid+it.first;
		fr(i,0,(it.second)/2){
			temp1+=(it.first);
		}
	}
	temp2=temp1;
	reverse(all(temp2));
	op=temp1+mid+temp2;
	cout<<(mid.size()<=1?op:"NO SOLUTION")<<nL;
	
}