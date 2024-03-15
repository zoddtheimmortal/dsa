/** 
 immortalzodd
 21.02.2024 17:56:30
 square
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

void solve(){
	vector<pair<int,int>> arr(4);
	for(auto &x:arr) cin>>x.first>>x.second;
	int pivot=arr[0].first,y=arr[0].second,side=-1;
	fr(i,1,4){
		if(arr[i].first==pivot){
			side=arr[i].second-y;
			break;
		}
	}

    cout<<side*side<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}