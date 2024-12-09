/** 
 immortalzodd
 26.06.2024 19:50:41
 fence
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

ll n,k;
vi arr;

void solve(){
	cin>>n>>k;
	arr.resize(n); for(int&x:arr) cin>>x;

    int minsum=INT_MAX,cursum=0,idx=0;
    int si=0,ei=0;
    while(ei<k) cursum+=arr[ei++];
    minsum=cursum;
    while(ei<n){
    	cursum+=arr[ei]-arr[si];
    	if(minsum>cursum){
    		minsum=cursum;
    		idx=si+1;
    	}
    	si++;
    	ei++;
    }
    cout<<idx+1<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}