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
	int n,s; cin>>n>>s;
	vi arr(n); fr(i,0,n) cin>>arr[i];
	vector<int> ans; 
        ll temp=0,l=0,r=0;
        for(int i=0;i<arr.size();i++){
            temp+=arr[i];
            if(temp==s){
            	cout<<temp<<nL;
                r=i;
                break;
            }
            else if(temp>s){
                l=i;
                temp=arr[i];
            }
        }
        ans.push_back(l); ans.push_back(r);
        cout<<l<<" "<<r<<nL;
}