/** 
 immortalzodd
 17.07.2024 21:44:40
 slidingWindowMedian
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
vl arr;
multiset<ll> up,low;

void ins(ll val){
	if(val<=*low.rbegin()){
		low.insert(val);
		if(low.size()>(k+1)/2){
			up.insert(*low.rbegin());
			low.erase(low.find(*low.rbegin()));
		}
	}
	else{
		up.insert(val);
		if(up.size()>k/2){
			low.insert(*up.begin());
			up.erase(up.find(*up.begin()));
		}
	}
}

void er(ll val){
	if(up.find(val)!=up.end()) up.erase(up.find(val));
	else low.erase(low.find(val));
	if(low.empty()){
		low.insert(*up.begin());
		up.erase(up.find(*up.begin()));
	}
}

void solve(){
    cin>>n>>k;
    arr.resize(n); for(ll&x:arr) cin>>x;
    low.insert(arr[0]);
    fr(i,1,k) ins(arr[i]);
    cout<<*low.rbegin()<<" ";
    fr(i,k,n){
    	if(k==1){
    		ins(arr[i]);
    		er(arr[i-k]);
    	}else{
    		er(arr[i-k]);
    		ins(arr[i]);
    	}
    	cout<<*low.rbegin()<<" ";
    }
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