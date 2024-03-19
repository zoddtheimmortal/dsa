#include<stdio.h>
int swap(int arr[],int arr2[],int n);
int find(int arr[],int arr2[],int n);
int main(){
	int n;scanf("%d",&n);	
	int a1[n],a2[n];
	for(int i=0;i<n;i++){
		a1[i]=1;
	}
	for(int i=1;i<=n-1;i++){
		find(a1,a2,n);
		swap(a1,a2,n);
	}
	printf("%d",a1[n-1]);
}

int swap(int a1[],int a2[],int n){
	for(int i=0;i<n;i++){
		a1[i]=a2[i];
		a2[i]=0;
	}
}

int find(int a1[],int a2[],int n){
	a2[0]=1;
	for(int i=1;i<n;i++){
		a2[i]=a1[i]+a2[i-1];
	}
}
