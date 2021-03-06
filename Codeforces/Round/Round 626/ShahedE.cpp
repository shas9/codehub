#include<bits/stdc++.h>

using namespace std;

#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define LL                      long long
#define ULL                     unsigned long long
#define pb                      push_back
#define tcase                   cout<<"Case "<<C++<<": ";
#define all(a)                  a.begin(),a.end()
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end
#define ABS(x)                  ((x)<0?-x(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define PI                      acos(-1.0)
#define ff                      first
#define ss                      second
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define FastRead                ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(x, l, r)            for (int x = l; x<=r; ++x)
#define REP(x,r)                for (int x = 0; x <r; ++x)
#define NN                      cout<<"\n";
#define NNN                     cout<<"\n------------------------------\n";

//***********************************************************************//
//                      SHAHED AHMED, CSE'15, IUT                        //
//***********************************************************************//
LL n,p,k;
vector<pair<LL,LL> > a;
vector<LL> s[100010];

int Set(int num, int pos) {
	return num | (1 << pos);
}

bool Check(int num, int pos) {
	return (bool)(num & (1 << pos));
}

LL dp[100005][1<<7];

LL func(int pos,int mask)
{

    if(dp[pos][mask]!=-1)
    {
        return dp[pos][mask];
    }

    LL baki = __builtin_popcount(mask);

    int rem = 0;

    for(int i = 0; i < p; i++)
    {
        if(Check(mask,i)) rem++;
    }

//    cout << rem << " " << baki << endl;
    if(pos==n)
    {
        if(baki) return 0;
        else return -1e18;
    }

    LL audi = pos - baki;

    LL ret;

    if(audi<k)
    {
        ret = func(pos+1,mask) + a[pos].first; // as audi
    }
    else
    {
        ret = func(pos+1,mask);
    }

    for(int i=0;i<p;i++)
    {
        if(Check(mask,i)) continue;
        ret = max(ret, func(pos+1,Set(mask,i)) + s[a[pos].ss][i] );
    }

    return dp[pos][mask]=ret;

}

int main()
{
    freopen("input.txt", "r", stdin);

    FastRead
    memset(dp,-1,sizeof dp);
    cin>>n>>p>>k;
    LL x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.pb({-x,i});
    }
    sort(all(a));

    for(auto &u:a) u.ff*=-1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            cin>>x;
            s[i].pb(x);
        }
    }

    cout<<func(0,0);
}

