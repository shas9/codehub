#include<stdio.h>
int main()
{
    int n,m,p,i,j,k,tmp,sum,lane,bench;
    char c;

    scanf("%d%d%d",&n,&m,&p);
    tmp=m*2;
    lane=p/tmp;
    if(p%tmp!=0)
        lane++;
    tmp=p-((lane-1)*tmp);
    bench=(tmp/2);
    if(tmp%2==0){
        c='R';
    }
    else{
        bench++;
        c='L';
    }
    printf("%d %d %c\n",lane,bench,c);
    return 0;
}
