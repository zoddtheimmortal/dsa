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
	int t; cin>>t;
	while(t--){
		ll n,k; cin>>n;
		k=n; ll base=9,i=1,sum=0;
		for(;;i++){
			//>=0 stupid fucking edge case
			if(k-(i*(base))>0){
				k-=i*(base);
				sum+=base;
				base*=10;
			}
			else break;
		}
		ll num=(sum+(k/i)),pos=(k%i);
		//pos has a delay of one
		if(k%i>0){
			pos-=1;
			num++;
		}
		else{
			pos=i-1;
		}
		string str=to_string(num);
		// cout<<str[pos]<<" "<<str<<" "<<i<<nL;
		cout<<str[pos]<<nL;
	}
}