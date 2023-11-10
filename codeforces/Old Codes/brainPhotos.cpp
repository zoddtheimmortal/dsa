#include<iostream>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
	int bw=0;
	for(int i=1;i<=(n*m);i++){
		char c; cin>>c;
		if(c=='B'||c=='W'||c=='G') bw++;
	}
	if(bw==n*m) cout<<"#Black&White";	
	else cout<<"#Color";
}