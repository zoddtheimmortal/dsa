#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void solve(){
    ll n,k,total=0; cin>>n>>k;
    vi arr(n);
    fr(i,0,n){
    	cin>>arr[i];
    	total+=arr[i];
    }
    vi motu,tomu;
    fr(i,0,n){
    	if(i%2==0) motu.pb(arr[i]);
    	else tomu.pb(arr[i]);
    }
    sort(all(motu),greater<int>());
    sort(all(tomu),greater<int>());
    ll tScore=0,mScore=0,t=0,m=0;
   	while(m+t<k){
   		if(motu[m]>tomu[t]){
   			tScore+=motu[m++];
   		}
   		else tScore+=tomu[t++];
   	}
   	while(m+t<tomu.size()) tScore+=tomu[t++];
    mScore=total-tScore;
    cout<<tScore<<" "<<mScore<<nL;
   	cout<<(tScore>mScore?"YES":"NO")<<nL;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}