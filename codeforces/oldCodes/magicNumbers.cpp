#include<bits/stdc++.h>
using namespace std;
int magicNumber(string str);
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str; cin>>str;
	cout<<(magicNumber(str)?"YES":"NO")<<"\n";	
}

int magicNumber(string str){
	for(int i = 0; i < str.size();){
		if(i<str.size()-2 && str[i]=='1' && str[i+1]=='4' && str[i+2]=='4'){
			i+=3;
		}
		else if(i<str.size()-1 && str[i]=='1' && str[i+1]=='4'){
			i+=2;
		}
		else if(str[i]=='1'){
			i++;
		}
		else return 0;
	}
	return 1;
}