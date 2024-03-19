#include<iostream>
using namespace std;
void decoderStr(char str[]);
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		char str[n]; cin>>str;
		decoderStr(str);
		cout<<str<<endl;
	}	
}

void decoderStr(char str[]){
	if(str[0]=='\0') return;
	else if(str[2]!='0' || str[3]=='0'){
		str[0]=('a'+(str[0]-'0')-1);
		decoderStr(str+1);
	}
	else{
		int x=((str[0]-'0')*10)+str[1]-'0';
		str[0]=('a'+x-1);
		int i=1;
		str+=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		decoderStr(str);
	}
}