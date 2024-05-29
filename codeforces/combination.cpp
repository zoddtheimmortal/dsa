/** 
 immortalzodd
 27.05.2024 11:34:04
 combination
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

bool compare(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second) return a.first>b.first;
	return a.second>b.second;
}

void solve(){
    ll n; cin>>n;
    vector<pair<int,int>> arr(n,{0,0});
    for(pair<int,int>&p:arr) cin>>p.first>>p.second;
    sort(all(arr),compare);
	int left=1,i=0,score=0;
	while(left>0&&i<n){
		pair<int,int> p=arr[i++];
		score+=p.first;
		left+=p.second-1;
	}
	cout<<score<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}