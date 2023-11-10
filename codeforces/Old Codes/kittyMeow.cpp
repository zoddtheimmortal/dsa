#include<iostream>
using namespace std;
void lCase(char str[]);
void removeConsec(char str[]);
int compareStr(char s1[],char s2[]);
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		char str[51]; cin>>str;
		lCase(str);
		removeConsec(str);
		char s2[]="meow";
		int x=compareStr(str,s2);
		if(x==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
}

void lCase(char str[]){
	for(int i=0;str[i]!='\0';i++){
		if(str[i]>=65 && str[i]<=90){
			str[i]+=32;
		}
	}
	return;
}

void removeConsec(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]==str[1]){
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		removeConsec(str);
	}
	else{
		removeConsec(str+1);
	}
}

int compareStr(char s1[],char s2[]){
	int x=0,y=0;
	for(;s1[x]!='\0';x++); for(;s2[y]!='\0';y++);
	if(x!=y) return 0;
	for(int i=0;s1[i]!='\0';i++){
		if(s1[i]!=s2[i]) return 0;
	}
	return 1;
}