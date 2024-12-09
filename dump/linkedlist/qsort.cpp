/** 
 immortalzodd
 19.08.2024 23:46:32
 qsort
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

int partition(vi&arr,int si,int ei){
	int pivot=arr[si];
	int i=si,j=ei;

	while(i<j){
		while(arr[i]<=pivot&&i<=ei-1) i++;
		while(arr[j]>pivot&&j>=si+1) j--;
		if(i<j) swap(arr[i],arr[j]);
	}

	swap(arr[j],arr[si]);
	return j;
}

void qsort(vi& arr,int si,int ei){
	if(si>=ei) return;
	int p=partition(arr,si,ei);
	qsort(arr,si,p-1);
	qsort(arr,p+1,ei);
}

void solve(){
	int n; cin>>n;
    vi arr(n,0); for(int&x:arr) cin>>x;
    qsort(arr,0,n-1);
    for(int&x:arr) cout<<x<<" ";
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