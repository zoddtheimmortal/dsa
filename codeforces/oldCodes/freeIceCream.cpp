#include<iostream>
using namespace std;
int main(){
	long long int n,x; cin>>n>>x;
	long long int child=0;
	while(n--){
		char sign; long long int ice; cin>>sign>>ice;
		if(sign=='+') x+=ice;
		else if(sign=='-' && x>=ice){
			x-=ice;
		}
		else if(sign=='-' && x<ice){
			child++;
		}
	}
	cout<<x<<' '<<child<<endl;
}