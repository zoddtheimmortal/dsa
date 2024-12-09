/** 
 immortalzodd
 09.06.2024 12:09:14
 alphabeticRemovals
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pci = pair<char,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,k;
vector<pci> arr;

bool ixSort(pci a,pci b){
	return a.second<b.second;
}

void solve(){
    cin>>n>>k;
    arr.resize(n);
    fr(i,0,n){
    	cin>>arr[i].first;
    	arr[i].second=i;
    }
    sort(all(arr));
    sort(arr.begin()+k,arr.end(),ixSort);
    fr(i,k,n) cout<<arr[i].first;
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