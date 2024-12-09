/** 
 immortalzodd
 04.08.2024 19:13:26
 preprocessDates
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

void solve(){
	int n; cin>>n;
	vector<string> arr(n);
	for(string&s:arr) cin>>s;

	map<string,string> mp;
	mp["Jan"]="01"; mp["Feb"]="02";

	for(string&s:arr){
		string day="",mnth="",yr="";
		int k=s.size();
		yr=s.substr(k-4,4);
		int i=3;
		if(isdigit(s[1])){
			day=s.substr(0,2);
			i++;
		}
		else{
			day='0'+s.substr(0,1);
		}
		mnth=mp[s.substr(i,3)];
		cout<<yr<<"-"<<mnth<<"-"<<day<<nL;
	}
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}