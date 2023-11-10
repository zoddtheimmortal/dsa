#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,p; cin>>n>>p;
	vi arr(n); fr(i,0,n) cin>>arr[i];
	ll temp=0,count=1,tempmax=1;
	fr(i,0,n){
		temp+=arr[i];
		if(temp<p){
			tempmax++;
		}
		else{
			tempmax=1;
			temp=arr[i];
		}
		count=max(count,tempmax);	
	}
	cout<<count<<nL;
}