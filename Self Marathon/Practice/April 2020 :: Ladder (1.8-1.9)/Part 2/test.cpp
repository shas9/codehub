#include<bits/stdc++.h>
using namespace std;
#define scl(n) scanf("%d",&n)
#define ll int

int dsu[402][115000],ara[200005],nxt[402],track[402][10002];
const int sz = 500;
const int stt = 10000;

ll fnd(ll blk, ll idx)
{
	if(dsu[blk][idx] <= stt) return idx;

	return dsu[blk][idx] = fnd(blk,dsu[blk][idx]);
}

int main()
{
    //freopen("input16.txt","r",stdin);
    //freopen("output16.txt","w",stdout);
    int n,m,i,j,k,a,b,c,x,y,z,l,r,p,q;
    scl(n);
    for(i=0;i<=400;i++){
        nxt[i]=stt+500 + 1;
    }
    for(i=1;i<=n;i++){
        scl(ara[i]);
        int blk =i/sz;
        int idx =i%sz;
        idx  += (stt + 1);

        if(track[blk][ara[i]]==0){
            track[blk][ara[i]]=++nxt[blk];
            dsu[blk][nxt[blk]]=ara[i];
        }
        dsu[blk][idx]=track[blk][ara[i]];
    }
    ll qq;
    scl(qq);
    ll t;
    for(t=1;t<=qq;t++)
    {

        scl(l);
        scl(r);
        scl(x);
        scl(y);
        if(x==y){
            continue;
        }
        //cout<<t<< " "<<l<< " " <<r<< " " <<p<< " " <<q<<endl;
        int lblock =l/sz;
        int rblock=r/sz;
//        if(track[x][q]==0 || track[y][q]==0)
        {
            if(track[lblock][y]==0){
                track[lblock][y]=++nxt[lblock];
                dsu[lblock][nxt[lblock]]=y;
            }
            if(track[rblock][y]==0){
                track[rblock][y]=++nxt[rblock];
                dsu[rblock][nxt[rblock]]=y;
            }
            //nxt++;
        }

        for(i=l; i<=r && i/sz==lblock && i<=n;i++)
        {
            int idx =i%sz;
            idx+=(stt + 1);
            int val=fnd(lblock,idx);
            val=dsu[lblock][val];
            if(val != x)
                continue;
            dsu[lblock][idx]=track[lblock][y];


        }
        //cout<<t<< " " <<qq<<endl;
        if(lblock == rblock)
            continue;


        for(i=r;i>0 && i/sz==rblock;i--)
        {
            int idx =i%sz;
            idx+=(stt + 1);
            int val =fnd(rblock,idx);
            val=dsu[rblock][val];
            if(val!=x)
                continue;
            dsu[rblock][idx]=track[rblock][y];
        }


        for(i=lblock+1;i<rblock;i++)
        {
            if(track[i][x]==0)
                continue;
            if(track[i][y]==0){
                track[i][y]=track[i][x];
                dsu[i][track[i][x]]=y;
            }
            else{
                dsu[i][track[i][x]]=track[i][y];
            }
            track[i][x]=0;
        }

        //cout<<t<<"   "<<q<<endl;
    }

    for(i=1;i<=n;i++)
    {
        int blk =i/sz;
        int idx =i%sz;
        idx += stt + 1;
        int ans=fnd(blk,idx);
        ans =dsu[blk][ans];
        printf("%d",ans);
        if(i<n)
            printf(" ");
    }
    cout<<endl;

}

