#include<iostream>
using namespace std;
void merge(int l[],int r[],int arr[],int a,int b);
int main(){
	int n1,n2; cin>>n1>>n2;	
	int* l=new int[n1],*r=new int[n2];
	for(int i=0;i<n1;i++) cin>>l[i];
	for(int i=0;i<n2;i++) cin>>r[i];
	int* merged=new int[n1+n2];
	merge(l,r,merged,n1,n2);
	for(int i=0;i<n1+n2;i++) cout<<merged[i]<<" ";
	delete[] l,r,merged;
}

void merge(int l[],int r[],int arr[],int a,int b){
	int i=0,j=0,k=0;
	while(i<a && j<b){
		if(l[i]<r[j]){
			arr[k++]=l[i++];
		}
		else{
			arr[k++]=r[j++];
		}
	}
	while(i<a){
		arr[k++]=l[i++];
	}
	while(j<b){
		arr[k++]=r[j++];
	}
}