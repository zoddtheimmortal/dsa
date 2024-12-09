/** 
 immortalzodd
 17.07.2024 22:15:24
 subarrayDistinctValues
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

    int si=0,ei=0,dist=0;
    ll ans=0;
    map<int,int> freq;
    while(si<n){
    	while(ei<n){
    		if(freq.count(arr[ei])==0&&dist==k) break;

    		if(freq.count(arr[ei])==0){
    			dist++;
    			freq[arr[ei]]=1;
    		}else freq[arr[ei]]++;
    		ei++;
    	}
    	ans+=(ei-si);
    	if(freq[arr[si]]==1){
    		dist--;
    		freq.erase(arr[si]);
    	}else freq[arr[si]]--;
    	si++;
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