#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fr(i, a, b) for (int i = a; i < (b); ++i)
#define rf(i, a, b) for (int i = b; i >=(a); i--)
#define nL "\n"

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		int si=0,ei=n,a=n,b=0,flag=-1;
		while(si<=ei){
			int mid=si+(ei-si)/2;
			int a1=a-mid,b1=mid,temp=((a1*(a1-1))/2)+((b1*(b1-1))/2);
			if(temp==k){
				a=n-mid; b=mid; flag=1;
				break;
			}
			else if(temp<k) si=mid+1;
			else ei=mid-1;
		}
		if(flag==1){
			cout<<"YES"<<nL;
			// cout<<a<<" "<<b<<endl;
			fr(i,0,a) cout<<1<<" ";
			fr(i,0,b) cout<<-1<<" ";
			cout<<nL;
		}
		else cout<<"NO\n";
	}
}

