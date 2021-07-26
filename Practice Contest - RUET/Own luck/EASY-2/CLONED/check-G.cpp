#include<stdio.h>
#include<math.h>

double volume(int r1,int r2,int h,int p)
{
    double pi,y1,y2,R,v;
    pi=2*acos(0.0);
    y1=r1*h/(r1-r2);
    y2=y1+p-h;
    R=y2*r2/(y2-p);
    v=(pi*p*(R*R+R*r2+r2*r2))/3;
    return v;
}
int main()
{
    int r1,r2,h,p,t,i;
    double v;
    do{
    scanf("%d",&t);}while(t>100);
    for(i=1;i<=t;i++)
    {
        do{
            scanf("%d %d %d %d",&r1,&r2,&h,&p);
        }while(r2<1||r1<r2||r1>100||p<1||p>h||h>100);
        v=volume(r1,r2,h,p);
        printf("Case %d: %.08lf",i,v);
        if(i<t)
            printf("\n");

    }
    return 0;

}
