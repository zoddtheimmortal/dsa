/** 
 immortalzodd
 08.04.2024 13:43:23
 evaluateReversePolishNotation
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
    ll n; cin>>n;
    vector<string> arr(n); for(auto&x:arr) cin>>x;

    stack<int> ss;
    int ans=0;
    bool first=true;
    for(auto&x:arr){
    	if(x!="+"&&x!="-"&&x!="/"&&x!="*"){
                ss.push(stoi(x));
            }
            else if(first){
                int a=ss.top(); ss.pop();
                int b=ss.top(); ss.pop();

                if(x=="+") ans+=(b+a);
                else if(x=="-") ans+=(b-a);
                else if(x=="/") ans+=(b/a);
                else if(x=="*") ans+=(b*a);

                first=false;
            }else{
                int a=ss.top(); ss.pop();

                if(x=="+") ans=a+ans;
                else if(x=="-") ans=a-ans;
                else if(x=="/") ans=a/ans;
                else if(x=="*") ans=a*ans;
            }
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