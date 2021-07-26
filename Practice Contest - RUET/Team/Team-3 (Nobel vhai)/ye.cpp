#include<stdio.h>
int main()
{
    long long a1,a2,b1,b2,c1,c2,i,j,tmp;
    scanf("%lld%lld%lld%lld%lld%lld",&a1,&a2,&b1,&b2,&c1,&c2);
    tmp=((a1*b2)-(b1*a2))+((b1*c2)-(c1*b2))+((c1*a2)-(a1*c2));
    if(tmp==0){
        printf("No\n");
        return 0;
    }
    else{
        i=((a1-b1)*(a1-b1))+((a2-b2)*(a2-b2));
        j=((b1-c1)*(b1-c1))+((b2-c2)*(b2-c2));
        if(i==j)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
