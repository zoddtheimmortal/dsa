/** 
 immortalzodd
 04.08.2024 21:50:08
 doTheyBelong
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

using pii = pair<int,int>;

double area(pii a,pii b,pii c){
	auto[x1,y1]=a;
	auto[x2,y2]=b;
	auto[x3,y3]=c;
	return abs(1.0*(x3*(y1-y2)+x2*(y3-y1)+x1*(y2-y3))/2.0);
}

double distance(pii a,pii b){
	auto [x1,y1]=a;
	auto[x2,y2]=b;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool tri(pii a,pii b,pii c){
	double ab,bc,ac;
	ab=distance(a,b);
	bc=distance(b,c);
	ac=distance(a,c);

	return (ab+bc>ac)&&(ac+ab>bc)&&(bc+ac>ab);
}

bool fits(pii a,pii b,pii c,pii p){
	double A,a1,a2,a3;
	A=area(a,b,c);
	a1=area(a,b,p);
	a2=area(b,c,p);
	a3=area(a,c,p);

	return A==a1+a2+a3;
}

void solve(){
    pii a,b,c;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;

    pii p,q;
    cin>>p.first>>p.second;
    cin>>q.first>>q.second;

    if(!tri(a,b,c)){
    	cout<<0<<nL;
    	return;
    }

    bool bp=fits(a,b,c,p);
    bool bq=fits(a,b,c,q);

    if(bp&&bq) cout<<3<<nL;
    else if(bp&&!bq) cout<<1<<nL;
    else if(!bp&&bq) cout<<2<<nL;
    else cout<<4<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}