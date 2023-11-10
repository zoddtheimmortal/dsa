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
#define fr(i, a, b) for (int i = a; i < (b); ++i)
#define rf(i, a, b) for (int i = b; i >=(a); i--)
#define nL "\n"
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n; cin>>n;
	ll base=(log2(n))/log2(5),zero=0;
	fr(i,1,base+1){
		ll add=n/(pow(5,i));
		zero+=add;
	}
	cout<<zero<<nL;
}