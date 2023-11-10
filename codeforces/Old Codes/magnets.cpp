#include<iostream>
using namespace std;
int main(){
	int n; cin>>n;	
	int* a=new int[n];
	int count=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a>0){
			if(a[i]!=a[i-1]) count++; 
		}
	}
	cout<<count;
}