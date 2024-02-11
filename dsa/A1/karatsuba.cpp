/**
 immortalZodd
 19.01.2024 22:25:00
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

int makeEqual(string &a,string &b){
	int l1=a.size(),l2=b.size();
	int len=max(l1,l2);

	fr(i,0,len-l1) a="0"+a;
	fr(i,0,len-l2) b="0"+b;

	return len;
}

string addStrings(string &a,string &b){
	int len=makeEqual(a,b);
	string ans;
	int i=0,sum=0,carry=0;
	while(len>0){
		sum=(a[len-1]-'0'+b[len-1]-'0'+carry)%10;
		carry=(a[len-1]-'0'+b[len-1]-'0'+carry)/10;
		ans[i++]=sum+'0';
		len--;
	}
	if(carry>0) ans[i++]=carry+'0';
	reverse(all(ans));
	cout<<ans<<nL;
	return ans;
}

void solve(){
    string a,b; cin>>a>>b;
    cout<<addStrings(a,b)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}