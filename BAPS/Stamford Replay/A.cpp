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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 100002

using namespace std;

ll phi[1000006], prime[1000006]; //declaring the arrays of prime and phi

vector < ll > range[100005];

void sievephi() //we'll find phi and primes till n
{
    ll n = 100005;
    ll i,j;

    for(i=1; i<=n; i++) phi[i]=i; //initializing the members of phi

    phi[1]=1;   //initializing the first element
    prime[1]=1; //initializing the first element

    for(i=2; i<=n; i++)
    {
        if(!prime[i])   //if the number is prime
        {
            for(j=i;j<=n; j+=i)
            {
                prime[j+i]=1;   //all the numbers that are divisible by i are not prime
                phi[j]=(phi[j]/i)*(i-1);    //for the phi of a number n, we divide n with a prime number p such that n is divisible by p
                                            // and multiply it by (p-1), so we get the phi
            }
        }
    }
}

ll solve(ll r, ll x)
{
    ll lo = 0;

    ll hi = range[x].size() - 1;

    if(range[x].size() == 0) return 0;

    ll ans = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(range[x][mid] == r)
        {
            return ans = mid + 1;
        }

        if(range[x][mid] < r)
        {
            ans = mid + 1;

            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

//    cout << ans << endl;

    return ans;
}


int main()
{
    sievephi();

    ll i;

    for(i = 1; i <= 100000; i++)
    {
        range[phi[i]].push_back(i);
    }

    ll test;

    slld(i);
    slld(test);

    for(i = 1; i <= test; i++)
    {
        ll n, m, k;

        cin >> n >> m >> k;

        cout << solve(m,k) - solve(n - 1,k) << endl;
    }





    return 0;
}



