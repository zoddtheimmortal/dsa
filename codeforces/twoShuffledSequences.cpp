/** 
 immortalzodd
 02.06.2024 22:42:46
 twoShuffledSequences
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

ll n;
vi arr;

void solve(){
    cin>>n;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    sort(all(arr));
    vi inc={arr[0]},dec;
    fr(i,1,n){
    	if(arr[i]==arr[i-1]) dec.push_back(arr[i]);
    	else inc.push_back(arr[i]); 
    }
    sort(all(dec),greater<int>());
    fr(i,1,dec.size()){
    	if(dec[i]==dec[i-1]){
    		cout<<"NO"<<nL;
    		return;
    	}
    }
    cout<<"YES"<<nL;
    cout<<inc.size()<<nL;
    for(int&x:inc) cout<<x<<" ";
    cout<<nL<<dec.size()<<nL;
	for(int&x:dec) cout<<x<<" ";
	cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}