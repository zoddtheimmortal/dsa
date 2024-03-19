#include<iostream>
using namespace std;
#define abs(a) a>0?a:-a
int main(){
	int t; cin>>t;
	while(t--){
		int a,b,c; cin>>a>>b>>c;
		int step,n; step=abs((b-a)); n=2*(step);
		if(n>=a && n>=b){
			if(c<=n && (c+step)<=n && (c+step)!=a && (c+step)!=b){
				cout<<c+step<<endl;
			}
			else if(c<=n && (c-step)!=a && (c+step)!=b && (c-step)>0){
				cout<<c-step<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
		else{
			cout<<-1<<endl;
		}
	}	
}