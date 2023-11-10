#include<stdio.h>
#define ll long long

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k; scanf("%d %d %d",&n,&m,&k);
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    //make sum array with padding of 0 for x and y
    int sum[n+1][m+1];
    for(int i=0;i<n+1;i++){
        sum[i][m]=0;
    }
    for(int j=0;j<m+1;j++){
        sum[n][j]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum[i][j]=0;
            for(int p=i;p<n;p++){
                for(int q=j;q<m;q++){
                    sum[i][j]+=arr[p][q];
                }
            }
        }
    }

    //fix sx,sy with i and j, fix ex,ey with p and q and check sum
    int sx=-1,sy=-1,ex=-1,ey=-1,flag=0;
    ll temp=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int p=i;p<n;p++){
                for(int q=j;q<m;q++){
                    temp=(sum[i][j]-sum[i][q+1]-sum[p+1][j]+sum[p+1][q+1]);
                    if(temp==k){
                        sx=i,sy=j,ex=p,ey=q;
                        flag=1;
                        break;
                    }
                }
                if(flag==1) break;
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    if(flag==1){
        printf("%d %d\n",ex-sx+1,ey-sy+1);
        for(int i=sx;i<=ex;i++){
            for(int j=sy;j<=ey;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("-1\n");
    }
}