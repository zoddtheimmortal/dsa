#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

bool findKey(vi arr,int n,int key){
	bool foundHalf=false;
	int si=0,ei=n-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(!foundHalf){
			if(arr[mid]==key) return true;
			else if(arr[mid]>=arr[0] && arr[mid]<arr[n-1]){
				ei=mid-1;
				foundHalf=true;
			}
			else if(arr[mid]<arr[0] && arr[mid]>=arr[n-1]){
				
			}
		}
	}
}

void solve(){
    ll n,key; cin>>n>>key;
    vi arr(n,0);
    fr(i,0,n) cin>>arr[i];
    cout<<(findKey(arr,n,key)?"true":"false")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}