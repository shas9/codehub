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

#define maxn 10000007

using namespace std;

vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

vector < ll > palprime;

bool bit(ll num, ll pos)
{
    return (num & (1LL << pos));
}
bool check(ll num)
{
    string bin = "";

    bool tag = 0;
    for(ll i = 30; i >= 0; i--)
    {
        ll a = bit(num,i);
        if(a)
        {
            tag = 1;
        }

        if(tag)
        {
            bin += a + '0';
        }
    }

    //cout << num << " : " << bin << endl;

    string rev = bin;

    reverse(rev.begin(),rev.end());

    if(rev == bin)
    {
        //bug;
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    ll sz = primes.size();

    for(ll i = 0; i < sz; i++)
    {
        if(check(primes[i]))
        {
            palprime.pb(primes[i]);
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    sieve();
    solve();
    //slld(testcase);

    string in;
    while(cin >> in)
    {
        ll num = 0;

        ll sz = in.size();

        ll po = 1;
        for(i = sz - 1; i >= 0; i--)
        {
            if(in[i] == '1')
            {
                num += po;
            }

            po *= 2;
        }

        //cout << num << endl;

        //ll ans = upper_bound(palprime.begin(),palprime.end(),num) - uppe
        ll lt,rt,mt;
        lt=0,rt=palprime.size()-1;
        while(lt<=rt)
        {
            mt=(lt+rt)/2;
            if(palprime[mt]>=num){
                if(mt==0||palprime[mt-1]<num)
                    break;
                else{
                    rt=mt-1;
                }

            }
            else{
                    lt=mt+1;
                }
        }
        ll ta=palprime[mt];
        ll flagt=0;
        //cout<<ta<<endl;
        for(ll it=30;it>=0;it--){
            ll xt=(ta&(1ll<<it));
            if(xt==0&&flagt==1){
                printf("0");
            }
            else if(xt>0){
                printf("1");
                flagt=1;
            }
        }
        printf("\n");
    }


}

