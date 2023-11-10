#include<iostream>
using namespace std;
int main(){
	int k,n,w; cin>>k>>n>>w;
	int cost=((w*(w+1))/2)*k;
	(cost>n)?cout<<cost-n:cout<<0;	
}