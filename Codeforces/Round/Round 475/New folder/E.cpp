#include<bits/stdc++.h>
using namespace std;
int ara[100001],tree[4000001][2];
vector < int > nd[4000001];


int main()
{
    int test,t,i,j,k,a,b,c,x,y,z,n,m,nxt,tmp,q,nw;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&n,&q);
        for(i=0;i<=32*n;i++){
            tree[i][0]=0;
            tree[i][1]=0;
            nd[i].clear();
        }
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        nxt=1;
        for(i=1;i<=n;i++){
            nw=0;
            for(j=31;j>=0;j--){
                x=ara[i]&(1<<j);
                if(x>0){
                    x=1;
                }
                if(tree[nw][x]==0){
                    tree[nw][x]=nxt;
                    nxt++;
                    nw=nxt-1;
                }
                else{
                    nw=tree[nw][x];
                }
                if(j==0){
                    nd[nw].push_back(i);
                }
            }
        }
        for(i=0;i<q;i++)
        {
            scanf("%d",&m);
            nw=0;
            for(j=31;j>=0;j--){
                y=m&(1<<j);
                if(y>0)
                    y=1;
                z=(y+1)%2;
                if(tree[nw][z]!=0){
                    nw=tree[nw][z];
                }
                else{
                    nw=tree[nw][y];
                }
            }
            printf("%d\n",nd[nw][0]);
        }
        if(t!=test)
        printf("\n");

    }
}
