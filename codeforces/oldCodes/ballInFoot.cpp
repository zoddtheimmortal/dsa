#include<iostream>
using namespace std;

int stringMatch(char s1[],char s2[]);
int main(){
	int n; cin>>n;
	char team1[50],team2[50],holder[50];
	int count1=0,count2=0,flagCheck=0;
	for(int i=0;i<n;i++){
		if(i==0){
			cin>>team1;
			count1++;
		}
		else{
			cin>>holder;
			if(stringMatch(holder,team1)){
				count1++;
			}
			else if(stringMatch(holder,team1)==0 && flagCheck==0){
				int i=0;
				for(;holder[i]!='\0';i++){
					team2[i]=holder[i];
				}
				team2[i]='\0';
				count2++;
			}
			else{
				count2++;
			}
		}
	}
	if(count2>count1) cout<<team2<<'\n';
	else cout<<team1<<'\n';
}

int stringMatch(char s1[],char s2[]){
	int a=0,b=0;
	for(;s1[a]!='\0';a++); for(;s2[b]!='\0';b++);
	if(a!=b){
		return 0;
	}
	else{
		for(int i=0;s1[i]!='\0';i++){
			if(s1[i]!=s2[i]) return 0;
		}
		return 1;
	}
}