/** 
 immortalZodd
 18.02.2024 18:34:57
 recoveringASmallString
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

ll n;
int search(int lim){
	int si=1,ei=26,ans=0;
	while(si<=ei){
    	int mid=si+(ei-si)/2;
    	if(n-mid<=lim){
    		ans=mid;
    		ei=mid-1;
    	}else si=mid+1;
    }
    return ans;
}

void solve(){
	cin>>n;
	int x=search(52);
	n-=x;
	int y=search(26);
	n-=y;
	int z=n;
	char a=x+'a'-1,b=y+'a'-1,c=z+'a'-1;
	cout<<a<<b<<c<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}