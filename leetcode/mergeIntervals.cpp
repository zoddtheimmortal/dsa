/** 
 immortalzodd
 15.07.2024 21:27:08
 mergeIntervals
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

vector<vector<int>> merge(vector<vector<int>>& intr) {
        vector<vi> ans;
        sort(intr.begin(),intr.end());
        int i=0,j=1,n=intr.size();
        while(i<n&&j<n){
            if(intr[j-1][1]>intr[j][0]){
            	cout<<i<<" "<<j<<nL;
            	j++;
            }
            else{
            	ans.push_back({intr[i][0],intr[j-1][1]});
            	i=j++;
            }
        }
        while(i<n) ans.push_back(intr[i++]);
        return ans;
    }

void solve(){
    ll n; cin>>n;
    vector<vi> arr(n,vi(2,0));
    fr(i,0,n) cin>>arr[i][0]>>arr[i][1];
    vector<vi> ans=merge(arr);
    for(vi&v:ans) cout<<v[0]<<" "<<v[1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}