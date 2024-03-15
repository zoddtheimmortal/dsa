#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int m,k;

char* handleLow(char* low,int sum){
	int i=m-1;
	if(m==1 && k==0) return "0";
	while(sum!=k && i>=0){
		if(low[i]<'9'){
			low[i]++;
			sum++;
		}
		else{
			i--;
		}
	}
	if(sum!=k) return "-1";
	return low;
}

char* handleHigh(char* high,int sum){
	int i=m-1;
	if(m==1 && k==0) return "0";
	while(sum!=k && i>=0){
		if(high[i]>'0'){
			high[i]--;
			sum--;
		}
		else{
			i--;
		}
	}
	if(high[0]=='0') return "-1";
	if(sum!=k) return "-1";
	return high;
}

int main(){
	scanf("%d %d",&m,&k);
	char* low=(char*) malloc(sizeof(char)*m);
	char* high=(char*) malloc(sizeof(char)*m);

	for(int i=0;i<m;i++) high[i]='9';
	low[0]='1';
	for(int i=1;i<m;i++) low[i]='0';

	low=handleLow(low,1);
	high=handleHigh(high,9*m);

	printf("%s %s\n",low,high);
}