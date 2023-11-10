#include<stdio.h>
#define ll long long
#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a

void merge(int arr[],int si,int mid,int ei){
    int temp[ei-si];
    int i=si,j=mid+1,k=0;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
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

int find(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return 1;
    }
    return 0;
}

void printArray(int arr[],int n){
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0 && flag==0){
            flag=1;
            printf("%d\n",n-i);
        }
        if(flag==1){
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

int main(){
    int n1,n2; scanf("%d",&n1);
    int a[n1]; for(int i=0;i<n1;i++) scanf("%d",&a[i]);
    scanf("%d",&n2);
    int b[n2]; for(int i=0;i<n2;i++) scanf("%d",&b[i]);

    //union
    int setU[n1+n2];
    for(int i=0;i<n1+n2;i++) setU[i]=0;
    for(int i=0;i<n1;i++) setU[i]=a[i];
    int k=n1;
    for(int i=0;i<n2;i++){
        if(find(setU,n1+n2,b[i])!=1){
            setU[k++]=b[i];
        }
    }
    mergeSort(setU,0,n1+n2-1);
    printArray(setU,n1+n2);

    //intersection
    int size=min(n1,n2);
    int setI[size];
    for(int i=0;i<size;i++) setI[i]=0;
    int i=0,j=0;
    k=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            setI[k++]=a[i];
            i++;
            j++;
        }
    }
    mergeSort(setI,0,min(n1,n2)-1);
    printArray(setI,min(n1,n2));

    //difference
    size=n1;
    int setD[size];
    for(int i=0;i<size;i++) setD[i]=0;
    k=0;
    for(int i=0;i<n1;i++){
        if(find(b,n2,a[i])==0){
            setD[k++]=a[i];
        }
    }
    mergeSort(setD,0,n1-1);
    printArray(setD,n1);

}