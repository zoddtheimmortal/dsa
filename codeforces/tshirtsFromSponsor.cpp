/** 
 immortalzodd
 26.05.2024 18:54:10
 tshirtsFromSponsor
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

vector<string> S,M,L,XL,XXL;

void solve(){
	vector<vector<string>> pref(5);
	pref[0]={"S","M","L","XL","XXL"};
	pref[1]={"M","L","S","XL","XXL"};
	pref[2]={"L","XL","M","XXL","S"};
	pref[3]={"XL","XXL","L","M","S"};
	pref[4]={"XXL","XL","L","M","S"};

	map<string,int> mp,idx;
	idx["S"]=0,idx["M"]=1,idx["L"]=2,idx["XL"]=3,idx["XXL"]=4;
	fr(i,0,5) cin>>mp[pref[0][i]];
	int q; cin>>q;
	while(q--){
		string size; cin>>size;
		int k=idx[size];
		fr(i,0,5){
			if(mp[pref[k][i]]>0){
				cout<<pref[k][i]<<nL;
				mp[pref[k][i]]--;
				break;
			}
		}
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