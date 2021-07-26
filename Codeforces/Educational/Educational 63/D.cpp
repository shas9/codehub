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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}
vector < ll > negetive_point;
vector < ll > vec;
vector < bool > flag;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll x;

    while(cin >> n >> x)
    {
        negetive_point.clear();
        vec.clear();
        flag.clear();

        negetive_point.push_back(0);
        for(i = 0; i < n; i++)
        {
            slld(input);

            vec.push_back(input);

            if(input < 0 && i)
            {
                negetive_point.push_back(i);
            }
        }


        ll sz = negetive_point.size();

        for(i = 0; i < sz - 1; i++)
        {
            ll neg = 0;
            ll pos = 0;

            for(j = negetive_point[i]; j <= negetive_point[i + 1]; j++)
            {
                if(vec[j] < 0)
                {
                    neg += abs(vec[j]);
                }
                else
                {
                    pos += abs(vec[j]);
                }
            }

            if(neg < pos)
            {
                flag.push_back(0);
            }
            else flag.push_back(1);
        }

        sz = flag.size();

        ll mxcnt = 0;
        ll cnt = 0;
        ll mxpos = 0;

        if(x < 0)
        {
            for(i = 0; i < sz; i++)
            {
                if(flag[i])
                {
                    cnt++;
                }
                else
                {
                    if(mxcnt < cnt)
                    {
                        mxcnt = cnt;
                        mxpos = i - cnt;
                    }
                    cnt = 0;
                }
            }

            for(i = negetive_point[mxpos + 1]; i <= negetive_point[mxpos + cnt + 1]; i++)
            {
                vec[i] *= x;
            }
        }
        else
        {
            if(negetive_point.size())
            {
                for(i = 0; i < sz; i++)
                {
                    if(!flag[i])
                    {
                        cnt++;
                    }
                    else
                    {
                        if(mxcnt < cnt)
                        {
                            mxcnt = cnt;
                            mxpos = i - cnt;
                        }
                        cnt = 0;
                    }
                }

                for(i = negetive_point[mxpos] + 1; i < min(negetive_point[mxpos + 1 + cnt], n); i++)
                {
                    vec[i] *= x;
                }
            }
            else
            {
                for(i = 0; i < n; i++) vec[i] *= x;
            }
        }

        ll sum = 0;
        ll mxsum = 0;
        for(i = 0; i < n; i++)
        {
            cout << vec[i] << " ";
            sum += vec[i];

            if(sum < 0)
            {
                sum = 0;
            }

            mxsum = max(mxsum,sum);
        }



        cout << endl << mxsum << endl;
    }




}


