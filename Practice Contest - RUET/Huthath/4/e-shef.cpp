#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n) != EOF) {
    int i,j,k,ara[26][3]= {},x,y;
    char c[26][26],c1,c2;
    int x1=0,y1=0,x2=0,y2=0;
    for(i=0;i<n;i++){
        int z[26]={};

        for(j=0;j<n;j++){
            scanf(" %c",&c[i][j]);
            k=c[i][j]-'A';
            ara[k][0]++;
            z[k]++;
            if(z[k]>1){
                c1=c[i][j];
                x1=i+1;
                y1=j+1;
                x2=ara[k][1];
                y2=ara[k][2];
            }
            ara[k][1]=i+1;
            ara[k][2]=j+1;
        }
    }
    for(i=0;i<26;i++){
        if(ara[i][0]==n-1){
            c2=i+'A';
        }
    }
    if(x1!=0&&y1!=0){
        for(i=0,j=y1-1;i<n;i++){
            if(i!=(x1-1)&&c[i][j]==c1){
            printf("%d %d %c\n",x1,y1,c2);
            break;
            }
        }
        if(i==n){
            for(i=0,j=y2-1;i<n;i++){
                if(i!=(x2-1)&&c[i][j]==c1){
                printf("%d %d %c\n",x2,y2,c2);
                break;
                }
            }
        }
    }
    else{
        for(i=0;i<26;i++){
        if(ara[i][0]==n-1){
            c1=i+'A';
        }
        if(ara[i][0]==1||ara[i][0]==n+1){
            x=ara[i][1];
            y=ara[i][2];
        }
        }
        printf("%d %d %c\n",x,y,c1);
    }

    }
    return 0;
}

