/** 
 immortalzodd
 12.04.2024 15:33:54
 mixingWater
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

ll h,c,t;
long double diff;

bool check(int x){
	long double sum=0;
	sum+=(h*((x+1)/2))/x;
	sum+=(c*(x/2))/2;
	cout<<sum<<nL;

	if(diff>=abs(sum-t)){
		diff=abs(sum-t);
		return true;
	}
	return false;
}

void solve(){
	cin>>h>>c>>t;
	diff=INT_MAX;
    int si=1,ei=INT_MAX,ans=0;
    while(si<=ei){
    	int mid=si+(ei-si)/2;
    	if(check(mid)){
    		ei=mid-1;
    		ans=mid;
    	}
    	else si=mid+1;
    }

    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}