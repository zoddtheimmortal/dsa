/** 
 immortalzodd
 01.08.2024 19:29:49
 aggressiveCows
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

ll n,c;
vi arr;

bool check(vi& arr,int dist,int cows){
	int prev=arr[0],c=1;
	fr(i,1,n){
		if(arr[i]-prev>=dist){
			prev=arr[i];
			c++;
		}
	}
	return c>=cows;
}

void solve(){
	cin>>n>>c;
	arr=vi(n,0); for(int&x:arr) cin>>x;

	sort(all(arr));
	int si=1,ei=arr[n-1]-arr[0],ans=0;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(check(arr,mid,c)){
			ans=mid;
			si=mid+1;
		}else ei=mid-1;
	}
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}