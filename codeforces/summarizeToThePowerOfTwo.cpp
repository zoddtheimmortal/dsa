/** 
 immortalzodd
 25.06.2024 15:34:39
 summarizeToThePowerOfTwo
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
map<ll,int> mp;
vi arr;

void solve(){
    cin>>n;
    arr=vi(n,0);
    for(int&x:arr){
    	cin>>x;
    	mp[x]++;
    }
    int ans=0;
    fr(i,0,n){
    	bool rm=true;
    	fr(k,0,31){
    		if(mp.find((1<<k)-arr[i])!=mp.end()){
    			if(mp[(1<<k)-arr[i]]>=2||(mp[(1<<k)-arr[i]]==1&&(1<<k)!=2*arr[i])){
    				rm=false;
    			}
    		}
    	}
    	ans+=rm;
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