/** 
 immortalzodd
 27.05.2024 23:24:15
 bigSegment
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

bool compare(pi a,pi b){
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}

void solve(){
    int n; cin>>n;
    vector<pi> arr(n);
    for(pi&p:arr) cin>>p.first>>p.second;
    vector<pi> sorted=arr;
	sort(all(sorted),compare);
	pi mseg=sorted[0];
	int ans=0;
	for(pi&p:arr){
		if(mseg.first<=p.first&&p.second<=mseg.second) ans++;
	}
	if(ans>=n){
		int idx=0;
		fr(i,0,n){
			if(mseg.first==arr[i].first&&mseg.second==arr[i].second){
				idx=i; break;
			}
		}
		cout<<idx+1<<nL;
	} else cout<<-1<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}