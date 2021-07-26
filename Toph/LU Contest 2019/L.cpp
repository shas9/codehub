#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;



ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct node
{
    ll lx, ly, rx, ry;
};

node mark[100005];

map < pair < ll, ll >, ll > mp;

bool check(ll flag, ll prevx, ll prevy, ll xxx, ll yyy)
{
	if(mark[flag].lx == xxx && mark[flag].ly == yyy) return 1;
    else if(mark[flag].rx == prevx && mark[flag].ry == prevy) return 1;
    else if(mark[flag].rx == xxx && mark[flag].ry == yyy) return 1;
    else if(mark[flag].lx == prevx && mark[flag].ly == prevy) return 1;


    return 0;
}

bool solve(ll flag, ll prevx, ll prevy, ll xxx, ll yyy)
{
    if(prevx == -1)
    {
        if(mark[flag].lx == xxx && mark[flag].ly == yyy) return 1;
        else if(mark[flag].rx == xxx && mark[flag].ry == yyy) return 1;

        return 0;
    }
    else if(xxx == -1)
    {
        if(mark[flag].lx == prevx && mark[flag].ly == prevy) return 1;
        else if(mark[flag].rx == prevx && mark[flag].ry == prevy) return 1;

        return 0;
    }
    if(mark[flag].lx == -1)
    {
        if(mark[flag].rx == xxx && mark[flag].ry == yyy) return 1;
        else if(mark[flag].rx == prevx && mark[flag].ry == prevy) return 1;

        return 0;
    }
    else if(mark[flag].rx == -1)
    {
        if(mark[flag].lx == prevx && mark[flag].ly == prevy) return 1;
        else if(mark[flag].rx == xxx && mark[flag].ry == yyy) return 1;


        return 0;
    }
    else
    {

        if(mark[flag].lx == xxx && mark[flag].ly == yyy)
        {
            if(mark[flag].rx == prevx && mark[flag].ry == prevy) return 1;
        }
        else if(mark[flag].rx == xxx && mark[flag].ry == yyy)
        {
            if(mark[flag].lx == prevx && mark[flag].ly == prevy) return 1;
        }

        return 0;
    }

    return 0;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll len = 0;

    slld(len);

    ll prevx = -1, prevy = -1;
    ll xx, yy;
    ll xxx, yyy;

    ll cnt = 0;

    for(i = 1; i <= len + 1; i++)
    {
        xx = xxx;
        yy = yyy;

        if(i <= len)
        {
            slld(xxx);
            slld(yyy);
        }
        else
        {
            xxx = -1;
            yyy = -1;
        }

        if(i == 1) continue;

        cnt++;
        mp[make_pair(xx,yy)] = cnt;

        flag = cnt;

        mark[flag].lx = prevx;
        mark[flag].ly = prevy;
        mark[flag].rx = xxx;
        mark[flag].ry = yyy;

//        cout << prevx << " " << prevy << " " << xx << " " << yy<< " " << xxx << " " << yyy << endl;
        prevx = xx;
        prevy = yy;
    }

    ll mx = 0;
    cnt = 0;

    slld(len);

    prevx = -1;
    prevy = -1;


    for(i = 1; i <= len + 1; i++)
    {
        xx = xxx;
        yy = yyy;

        if(i <= len)
        {
            slld(xxx);
            slld(yyy);
        }
        else
        {
            xxx = -1;
            yyy = -1;
        }

        if(i == 1) continue;

        if(!(mp.find(make_pair(xx,yy)) != mp.end()))
        {
            cnt = 0;

        }
        else
        {
            flag = mp[make_pair(xx,yy)];

//            cout << prevx << " " << prevy << " " << xx << " " << yy<< " " << xxx << " " << yyy << endl;


            if(solve(flag,prevx,prevy,xxx,yyy))
            {
                cnt++;
            }
            else if(check(flag,prevx,prevy,xxx,yyy))
            {
//                bug;

                if(cnt == 0)
                {
                    cnt++;
                }
                else
                {
                    cnt++;
                    mx = max(mx,cnt);
                    cnt = 0;
                }
            }
            else
            {
                cnt = 0;
            }

        }

        mx = max(mx,cnt);

        prevx = xx;
        prevy = yy;
    }

    cout << mx << endl;




}


