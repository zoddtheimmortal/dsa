#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int digSum(char* a){
	int sum=0,i=0;
	while(a[i]!='\0') sum+=(a[i++]-'0');
	return sum;
}

char* handleHigh(char* high,int m,int k,int sum){
	int i=m-1;
	while(sum!=k && i>=0){
		if(high[i]-'0'>0){
			high[i]--;
			sum--;
		}
		else i--;
	}
	if(high[0]=='0') return "-1";
	if(sum!=k) return "-1";
	return high;
}

char* handleLow(char* low,int m,int k,int sum){
	int i=m-1;
	while(sum!=k && i>=0){
		if(low[i]-'0'<9){
			low[i]++;
			sum++;
		}
		else i--;
	}
	if(sum!=k) return "-1";
	return low;
}

int main(){
	int m,k; scanf("%d %d",&m,&k);
	char* low=(char*) malloc(sizeof(char)*m);
	char* high=(char*) malloc(sizeof(char)*m);

	for(int i=0;i<m;i++) high[i]='9';
	low[0]='1';
	for(int i=1;i<m;i++) low[i]='0';

	char* lw=handleLow(low,m,k,digSum(low));
	char* hg=handleHigh(high,m,k,digSum(high));

	printf("%s %s\n",lw,hg);

	free(low); free(high);
}