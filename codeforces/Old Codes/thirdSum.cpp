#include<iostream>
#include<string>
using namespace std;
int main(){	
	string s; cin>>s;\
	int sum=0;
	for(int i=0;i<s.length();i++){
		if(*(s+i)!="+") sum+=stoi(s[i]);
	}
}