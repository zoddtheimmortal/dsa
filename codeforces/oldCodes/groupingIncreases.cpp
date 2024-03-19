/** 
 immortalzodd
 23.02.2024 19:37:36
 groupingIncreases
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

void solve(){
    ll n; cin>>n;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    vi s1,s2;
    ll i=0,prev1=0,prev2=0;
    while(i<n){
    	if(prev1<prev2){
    		if(arr[i]<=prev1){
    			s1.push_back(arr[i]);
    			prev1=arr[i];
    		}else if(prev1<arr[i]&&arr[i]<=prev2){
    			s2.push_back(arr[i]);
    			prev2=arr[i];
    		}else if(arr[i]>prev2){
    			s1.push_back(arr[i]);
    			prev1=arr[i];
    		}
    	}else{
    		if(arr[i]<=prev2){
    			s2.push_back(arr[i]);
    			prev2=arr[i];
    		}else if(prev2<arr[i]&&arr[i]<=prev1){
    			s1.push_back(arr[i]);
    			prev1=arr[i];
    		}else if(arr[i]>prev1){
    			s2.push_back(arr[i]);
    			prev2=arr[i];
    		}
    	}
    	i++;
    }

    ll ans=0;
    fr(i,1,s1.size()) ans+=(s1[i]>s1[i-1]);
    fr(i,1,s2.size()) ans+=(s2[i]>s2[i-1]);
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