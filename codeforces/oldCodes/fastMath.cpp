#include<iostream>
#include<string>
using namespace std;
int main(){
	string n1,n2; cin>>n1>>n2;
	string str=n1;
	for(int i=0;i<n1.length();i++){
		if(n1[i]==n2[i]) str.replace(i,1,"0");
		else str.replace(i,1,"1");
	}
	cout<<str;
}