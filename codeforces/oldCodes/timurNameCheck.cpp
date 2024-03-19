 #include<iostream>
 using namespace std;
 int timurCheck(char str[]);
 int main(){
 	int t; cin>>t;
 	while(t--){
 		int n; cin>>n;
 		char str[100]; cin>>str;
 		if(n!=5) cout<<"NO\n";
 		else{
 			if(timurCheck(str)) cout<<"YES\n";
 			else{
 				cout<<"NO\n";
 			}
 		}
 	}	
 }

int timurCheck(char str[]){
 	 char s1[]="Timur";
 	 int flag=0;
 	 for(int i=0;str[i]!='\0';i++){
 	 	for(int j=0;s1[j]!='\0';j++){
 	 		if(str[i]==s1[j]){
 	 			flag++;
 	 			s1[j]='0';
 	 		}
 	 	}
 	 }
 	 if(flag==5) return 1;
 	 else return 0;
 }