#include<stdio.h>
#define ll long long
int main(){
    int n,m,k; scanf("%d %d %d",&n,&m,&k);
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int sx=-1,sy=-1,ex=-1,ey=-1;
    ll sum=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int p=i;p<n;p++){
                for(int q=j;q<m;q++){
                    sum=0;
                    for(int a=i;a<=p;a++){
                        for(int b=j;j<=q;b++){
                            sum+=arr[a][b];
                        }
                    }
                    if(sum==k){
                        sx=i; sy=j; ex=p; ey=q;
                        goto solved;
                    }
                }
            }
            
        }
    }

    solved:
        for(int i=sx;i<=ex;i++){
            for(int j=sy;j<=ey;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }


}