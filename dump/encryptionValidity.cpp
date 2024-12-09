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

ll n;
vi arr;

int mdiv(){
	map<int,int> mp;
	map<int,int> cnt;
	sort(arr.begin(),arr.end());
	int mx=arr[n-1],mn=arr[0];

	for(int&x:arr){
		cnt[x]++;
		mp[x]=1;
	}

	fr(i,mn,mx+1){
		for(int j=mn;i*j<=mx;j++){
			mp[i*j]+=cnt[i];
		}
	}

	int d=0;
	for(int&x:arr){
		cout<<x<<" "<<mp[x]<<nL;
		d=max(d,mp[x]);
	}
	return d;
}

void solve(){
    cin>>n;
    arr.assign(n,0);
    for(int&x:arr) cin>>x;

    cout<<mdiv()<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}