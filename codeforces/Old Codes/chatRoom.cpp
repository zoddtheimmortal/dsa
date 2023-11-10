#include<iostream>
using namespace std;
int main(){
	string str; cin>>str;
	transformString(str);
	if(str.compare("hello")==0) cout<<"YES\n";
	else cout<<"NO\n";	
}

void transformString(string str){
	for(int i=0;i<str.size()-1;i++){
		if(str[i]=='h' || str[i]=='e' || str[i]=='l' || str[i]=='o'){
			
		}
	}
}