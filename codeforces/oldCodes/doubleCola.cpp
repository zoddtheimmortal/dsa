#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n; cin>>n;
	n-=1;
	int k=(log2((n/5)+1));
	n-=(5*(pow(2,k)-1));
	int interval=(pow(2,k+1)-pow(2,k));
	n/=interval;
	string str[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
	cout<<str[n]<<endl;
}