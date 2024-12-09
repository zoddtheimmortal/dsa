/** 
 immortalzodd
 25.06.2024 18:47:49
 goodArray
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

const int MAX=1e6;

ll n;
vi arr,cnt(MAX+1,0);

void solve(){
    cin>>n;
    arr.resize(n);
    ll sum=0;
    for(int&x:arr){
    	cin>>x; cnt[x]++;
    	sum+=x;
    }
    vi ans;
    fr(i,0,n){
    	sum-=arr[i];
    	cnt[arr[i]]--;
    	if(sum%2==0&&sum/2<=MAX&&cnt[sum/2]>0) ans.push_back(i);
    	sum+=arr[i];
    	cnt[arr[i]]++;
    }
    cout<<ans.size()<<nL;
    for(int&x:ans) cout<<x+1<<" ";
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