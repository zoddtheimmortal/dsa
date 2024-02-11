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

ll search(vector<pair<int,int>> arr, ll n, ll x){
   ll si=0,ei=n-1,ans=-2;
   while(si<=ei){
      ll mid=si+(ei-si)/2;
      if(arr[mid].first<=x){
         si=mid+1;
         ans=mid;
      }
      else{
         ei=mid-1;
      }
   }
   return ans;
}

void solve(){
   ll n,k; cin>>n>>k;
   vector<pair<int,int>> arr(n);

   fr(i,0,n){
      cin>>arr[i].first>>arr[i].second;
   }
   
   sort(all(arr),compare);

   while(k--){
      ll x; cin>>x;
      ll idx=search(arr,n,x);
      ll ans=-2;

      if(0<=idx && idx<n-1){
         if(x<arr[idx].second){
            ans=0;
         }
         else{
            ans=arr[idx+1].first-x;
         }
      }
      if(idx<0){
         ans=arr[0].first-x;
      }
      if(idx>=n-1){
         if(x<arr[n-1].second){
            ans=0;
         }else{
            ans=-1;
         }
      }

      cout<<ans<<nL;
   }   
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}