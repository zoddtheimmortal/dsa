#include<iostream>
using namespace std;
void firstChanger(string str);
int capsCounter(string str);
void allChanger(string str);
int main(){
	string str; cin>>str;
	int countCaps=capsCounter(str);
	if(countCaps==str.size()){
		firstChanger(str);
	}	
	else if(countCaps>1){
		allChanger(str);
	}
	else{
		cout<<str<<endl;
	}
}

void firstChanger(string str){
	for(int i=1;i<str.size();i++){
		str[i]=str[i]+32;
	}
	cout<<str<<endl;
}

int capsCounter(string str){
	int caps=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='A' && str[i]<='Z') caps++;
	}
	return caps;
}

void allChanger(string str){
	str[0]-=32;
	for(int i=1;i<str.size();i++){
		str[i]=str[i]+32;
	}
	cout<<str<<endl;
}