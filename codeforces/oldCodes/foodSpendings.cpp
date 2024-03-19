#include<iostream>
using namespace std;
long long int foodBuy(long long int balance,long long int spent);
int main(){
	int t; cin>>t;
	while(t--){
		long long int x; cin>>x;
		long long int spent=foodBuy(x,0);
		cout<<spent<<endl;
	}
}

long long int foodBuy(long long int balance,long long int spent){
	if(balance<10){
		return spent+balance;
	}
	else if(balance%10==0){
		foodBuy(balance/10,spent+balance);
	}
	else{
		foodBuy(balance-10+1,spent+10);
	}
}