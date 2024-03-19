#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
int maxVotes(int init,int beat);
int main(){
	int t; cin>>t;
	while(t--){
		int a,b,c; cin>>a>>b>>c;
		cout<<maxVotes(a,max(b,c))<<" ";
		cout<<maxVotes(b,max(a,c))<<" ";
		cout<<maxVotes(c,max(a,b))<<endl;
	}	
}

int maxVotes(int init,int beat){
	if(init>beat) return 0;
	else{
		return (beat-init)+1;
	}
}