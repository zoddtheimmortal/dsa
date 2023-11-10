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

bool compare(pair<int,char> a1,pair<int,char> a2){
	return a1.first<a2.first;
}

void solve(){
     ll n; cin>>n;
     vector<pair<int,char>> arr(2*n);
     fr(i,0,n){
     	cin>>arr[i].first;
     	arr[i].second='+';
     }
     fr(i,n,2*n){
     	cin>>arr[i].first;
     	arr[i].second='-';
     }
     ll ans=0,temp=0;
     n*=2;
     sort(all(arr),compare);

     // rep(it,arr) cout<<it.first<<" "<<it.second<<nL;

     fr(i,0,arr.size()-1){
     	if(arr[i].first==arr[i+1].first && arr[i].second!=arr[i+1].second){
     		i++;
     		continue;
     	}
     	else{
     		if(arr[i].second=='+') temp++;
     		else temp--;
     	}
     	ans=max(ans,temp);
     }
     cout<<ans<<nL;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}