#include<stdio.h>

void merge(int arr[],int si,int mid,int ei){
    int temp[ei-si];
    int i=si,j=mid+1,k=0;
    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=ei){
        temp[k++]=arr[j++];
    }
    k=0;
    for(int i=si;i<=ei;i++){
        arr[i]=temp[k++];
    }
}

void mergeSort(int arr[],int si,int ei){
    if(si>=ei) return;
    int mid=si+(ei-si)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}

int main(){
    int n; scanf("%d",&n);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    int temp=1,tempMax=-1,mode=-1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) temp++;
        else temp=1;
        if(temp>tempMax){
            tempMax=temp;
            mode=arr[i];
        }
    }
    printf("%d %d\n",mode,arr[n/2]);
}