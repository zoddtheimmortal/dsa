#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(int a,int b){
    return a<b;
}

void heapify(int* arr,int* comp,int n,int i){
    int left=2*i+1,right=2*i+2,p=i;
    if(left<n&&cmp(comp[p],comp[left])) p=left;
    if(right<n&&cmp(comp[p],comp[right])) p=right;

    if(p!=i){
        int temp=arr[p];
        arr[p]=arr[i];
        arr[i]=temp;
        heapify(arr,comp,n,p);
    }
}

void buildHeap(int* arr,int* comp,int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr,comp,n,i);
}

int main(){
    int n,x; scanf("%d %d",&n,&x);
    int* arr=(int*) malloc(sizeof(int)*n); 
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int idx[n],k=0;

    for(int i=0;i<n;i++){
        if(arr[i]<x) idx[k++]=i+1;
    }
    buildHeap(idx,arr,k);
    
    for(int i=k-1;i>=0;i--){
        int temp=idx[i];
        idx[i]=idx[0];
        idx[0]=temp;
        heapify(idx,arr,i,0);
    }

    printf("%d\n",k);
    for(int i=0;i<k;i++) printf("%d ",idx[i]);
    printf("\n");
}