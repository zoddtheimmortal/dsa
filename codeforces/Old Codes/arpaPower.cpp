#include<iostream>
using namespace std;
int main(){
	int n; cin>>n;
	int arr[4]={6,8,4,2};
	cout<<((n==0)?1:arr[(n%4)])<<endl;	
}