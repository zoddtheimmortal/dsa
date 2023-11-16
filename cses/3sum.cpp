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

bool compare(pair<int,int> a1,pair<int,int> a2){
	return a1.first<a2.first;
}

void solve(){
     ll n,target; cin>>n>>target;
     vector<pair<int,int>> arr;
     fr(i,0,n){
     	int x; cin>>x;
     	arr.pb(make_pair(x,i));
     }
     sort(all(arr),compare);
     vi triplet; bool flag=false;
     fr(i,0,n){
     	int si=i+1,ei=n-1,sum=target-arr[i].first;
     	while(si<ei){
     		if(arr[si].first+arr[ei].first==sum){
     			triplet.pb(arr[i].second);
     			triplet.pb(arr[si].second);
     			triplet.pb(arr[ei].second);
     			flag=true;
     			break;
     		}
     		else if(arr[si].first+arr[ei].first<sum) si++;
     		else ei--;
     	}
     	if(flag==true) break;
     }
     if(flag==false) cout<<"IMPOSSIBLE";
     else{
     	rep(it,triplet) cout<<it+1<<" ";
     }
     cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}