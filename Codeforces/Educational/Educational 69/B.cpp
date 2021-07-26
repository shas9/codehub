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

vector < ll > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);



    cin >> n;

    {
        vec.clear();

        ll pos = -1;

        for(i = 0; i < n; i++)
        {
            slld(input);

            vec.push_back(input);

            if(input == n)
            {
                pos = i;
            }
        }


        i = pos - 1;
        j = pos + 1;

        ll rad = n;
        while(i >= 0 || j < n)
        {
            if(i >= 0 && j < n)
            {
                if(vec[i] < vec[j])
                {
                    if(rad > vec[j])
                    {
                        rad = vec[j];
                        j++;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return 0;
                    }

                }
                else
                {
                    if(rad > vec[i])
                    {
                        rad = vec[i];
                        i--;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
            else if(i < 0)
            {
                    if(rad > vec[j])
                    {
                        rad = vec[j];
                        j++;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
            }

            else if(j >= n)
            {
                    if(rad > vec[i])
                    {
                        rad = vec[i];
                        i--;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
            }
        }

        cout  << "YES" << endl;

        return 0;
    }


}

