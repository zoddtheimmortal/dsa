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

bool compare(pair<int,int> a1,pair<int,int> a2){
	if(a1.first==a2.first) return a1.second>a2.second;
	return a1.first<a2.first;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	vi gas(n),cost(n);
	fr(i,0,n){
		cin>>gas[i];
	}
	fr(i,0,n){
		cin>>cost[i];
	}

	vector<pair<int,int>> arr(n);
	fr(i,0,n){
		arr[i]=make_pair(cost[i],gas[i]);
	}
	vector<pair<int,int>> brr=arr;
	sort(all(arr),compare);

	int index=find(all(brr),make_pair(arr[0].first,arr[0].second))-brr.begin();

	ll tank=arr[0].second;
	fr(i,1,n){
		tank=tank+arr[i].second-arr[i].first;
		if(tank<=0){
			index=-1;
			break;
		}
	}
	if(tank-arr[0].first<0) index=-1;
	cout<<index<<nL;
}