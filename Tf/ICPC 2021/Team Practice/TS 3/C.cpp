#include<bits/stdc++.h>
using namespace std;

#define ll int
#define mp make_pair
#define pb push_back
#define sc second
#define fr first
#define scl(n) scanf("%d",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define scs(ch) scanf("%s", ch)
#define pll pair< ll,ll >
#define mod 1000000007
#define LL long long

set < ll > st;
set < ll > :: iterator it;

ll bsx[100],bsy[100],dp[100][100][2][2];

ll op(ll pos,ll mx,ll isx,ll isy)
{
    //cout<<pos<< " " <<mx<< " " <<isx<< " " <<isy<<endl;
    if(pos<0)
    {
        //cout<<mx<<endl;
        return mx;
    }
    ll &ret = dp[pos][mx][isx][isy];
    if(ret !=-1)
    {
        //cout<<"ues  "<< dp[pos][mx][isx][isy]<<endl;
        return ret;
    }
    ll x,y,z;
    x=isx;
    y=isy;
    if(bsx[pos]==1)x=0;
    if(bsy[pos]==1)y=0;
    z=op(pos-1,mx,x,y);
    if(z >= mod) z -= mod;


    if((isx && bsx[pos]==1))
    {
        y=isy;
        if(bsy[pos]==1)y=0;
        z+=op(pos-1,max(mx,pos+1),isx,y);
        if(z >= mod) z -= mod;
    }
    else if(!isx)
    {
        y=isy;
        if(bsy[pos]==1)y=0;
        z+=op(pos-1,max(mx,pos+1),isx,y);
        if(z >= mod) z -= mod;
    }
    //z%=mod;

    if((isy && bsy[pos]==1))
    {
        x=isx;
        if(bsx[pos]==1)x=0;
        z+=op(pos-1,max(mx,pos+1),x,isy);
        if(z >= mod) z -= mod;
    }
    else if(!isy)
    {
        x=isx;
        if(bsx[pos]==1)x=0;
        z+=op(pos-1,max(mx,pos+1),x,isy);
        if(z >= mod) z -= mod;
    }
    //z%=mod;

    //cout<<pos<< " " <<mx<< " " <<isx<< " " <<isy << "     "<<z<<endl;
    return ret=z;
}


int main()
{
    ll test,t,i,j,k,a,b,c,x,y,z,n,m;
    n=1e9;
    m=1e9;

    ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(i=0; i<=30; i++)
    {
        if( n&(1ll<<i) )
        {
            bsx[i]=1;
        }
        else
        {
            bsx[i]=0;
        }
        if( m&(1ll<<i) )
        {
            bsy[i]=1;
        }
        else
        {
            bsy[i]=0;
        }

    }
    for(i=0; i<30; i++)
    {
        for(j=0; j<=30; j++)
        {
            dp[i][j][0][0]=-1;
            dp[i][j][0][1]=-1;
            dp[i][j][1][0]=-1;
            dp[i][j][1][1]=-1;
        }
    }
    a=op(29,0,1,1);
    cin >> test;

    for(t=1; t<=test; t++)
    {
        cin >> n >> m;

        for(i=0; i<=30; i++)
        {
            if( n&(1ll<<i) )
            {
                bsx[i]=1;
            }
            else
            {
                bsx[i]=0;
            }
            if( m&(1ll<<i) )
            {
                bsy[i]=1;
            }
            else
            {
                bsy[i]=0;
            }

        }
        for(i=0; i<30; i++)
        {
            for(j=0; j<=30; j++)
            {
                //dp[i][j][0][0]=-1;
                dp[i][j][0][1]=-1;
                dp[i][j][1][0]=-1;
                dp[i][j][1][1]=-1;
            }
        }
        a=op(29,0,1,1);
        if(a >= mod)
            a -= mod;
        cout << a << "\n";
    }


    return 0;
}


