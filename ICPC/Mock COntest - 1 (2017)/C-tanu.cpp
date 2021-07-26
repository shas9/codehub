#include<stdio.h>
int main()
{
    int ara[10][10],n,test,t,i,j,k,sum,check[11],a,b,c,count;
    scanf("%d",&test);
    for(t=0,count=0;t<test;t++){
        int check[11]={};
        sum=0;
        count=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        if(n<5){
            printf("Case %d: %d\n",t+1,0);
        }
        else{
            if(n>=5){
                for(i=0;i<=n-2;i++){
                    for(j=0;j<=n-5;j++){
                        int check1[11]={};
                        for(a=0,b=0,sum=0;a<2;){
                            if(check1[ara[i+a][j+b]]==0){
                                check1[ara[i+a][j+b]]=1;
                                sum++;

                            }
                            else{
                                break;
                            }
                            b++;
                            if(b==5){

                                b=0;
                                a++;

                            }
                        }
                        if(sum==10)
                            count++;
                    }
                }
                for(i=0;i<=n-5;i++){

                    for(j=0,sum=0;j<=n-2;j++){
                        int check2[11]={};
                        for(a=0,b=0,sum=0;a<5;){

                            if(check2[ara[i+a][j+b]]==0){
                                check2[ara[i+a][j+b]]=1;
                                sum++;

                            }
                            else{
                                break;
                            }
                            b++;
                            if(b==2){

                                b=0;
                                a++;
                            }
                        }
                        if(sum==10){
                            count++;

                        }
                    }
                }
            }
            if(n==10){
                for(i=0;i<n;i++){
                    int check3[11]={};
                    for(j=0,sum=0;j<n;j++){
                        if(check3[ara[i][j]]==0){
                            check3[ara[i][j]]=1;
                            sum++;
                        }
                        else{
                            break;
                        }
                    }
                    if(sum==10)
                        count++;
                }
                for(j=0;j<n;j++){
                    int check4[11]={};
                    for(i=0,sum=0;i<n;i++){
                        if(check4[ara[i][j]]==0){
                            check4[ara[i][j]]=1;
                            sum++;
                        }
                        else
                            break;
                    }
                    if(sum==10)
                        count++;
                }
            }
            printf("Case %d: %d\n",t+1,count);
        }
    }
    return 0;
}
