/** 
 immortalzodd
 20.03.2024 00:03:54
 swapAndDelete
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

void solve(){
    string str; cin>>str;
    vi arr={0,0};
    for(auto&x:str) arr[(x-'0')]++;
    int n=str.size();
	for(int k=0;k<n+1;k++){
		if(k==n||arr[1-(str[k]-'0')]==0){
			cout<<n-k<<nL;
			break;
		}
		arr[1-(str[k]-'0')]--;
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}