// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string s, a, b;

bool solve()
{
    if(s.front() == '0' || s.back() == '0') return 0;
    ll c1 = 1, c2 = 1;

    a = "(";
    b = "(";

    vector < ll > csum;
    csum.assign(s.size() + 1, 0);

    for(ll i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == 0) csum[i] = 1;

        csum[i] += csum[i + 1];
    }

    ll last = 0;

    for(ll i = 1; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            ll diff = (i - last - 1);

            if(diff && c1 + c2 == 0) return 0;

            if(diff % 2 == 0)
            {
                if(c1 == 0)
                {
                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) a += '(';
                        else a += ')';
                    }

                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) b += ')';
                        else b += '(';
                    }
                }
                else
                {
                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) b += '(';
                        else b += ')';
                    }

                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) a += ')';
                        else a += '(';
                    }
                }
            }
            else
            {
                if(c1 <= c2)
                {
                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) a += '(';
                        else a += ')';
                    }

                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) b += ')';
                        else b += '(';
                    }

                    c2--;
                    c1++;
                }
                else
                {
                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) b += '(';
                        else b += ')';
                    }

                    for(ll j = last + 1; j < i; j++)
                    {
                        if(abs(j - last) & 1) a += ')';
                        else a += '(';
                    }
                    c2++;
                    c1--;
                }
            }

            if(c1 == 0 || c2 == 0)
            {
                c1++;
                c2++;
                a += '(';
                b += '(';
            }
            else if(i + 1 < s.size() && s[i + 1] == '0' && max(c1,c2) == 1)
            {
                c1++;
                c2++;
                a += '(';
                b += '(';
            }
            else
            {
                c1--;
                c2--;

                a += ')';
                b += ')';
            }

            last = i;
        }
    }

    ll cnt = 0;

    for(auto it: a)
    {
        if(it == '(') cnt++;
        else cnt--;

        assert(cnt >= 0);
    }

    cnt = 0;

    for(auto it: b)
    {
        if(it == '(') cnt++;
        else cnt--;

        assert(cnt >= 0);
    }

    return 1;
}

bool solve2()
{
    vector < ll > o,z;

    if(s.front() == '0' || s.back() == '0') return 0;

    for(ll i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') o.push_back(i);
        else z.push_back(i);
    }

    if(o.size() & 1) return 0;

    a.resize(s.size());
    b.resize(s.size());

    for(ll i = 0; i < o.size(); i++)
    {
        if(i < (o.size() / 2)) a[o[i]] = b[o[i]] = '(';
        else a[o[i]] = b[o[i]] = ')';
    }

    for(ll i = 0; i < z.size(); i++)
    {
        if(i & 1) a[z[i]] = ')', b[z[i]] = '(';
        else a[z[i]] = '(', b[z[i]] = ')';
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> s;

        if(solve2()) cout << "YES\n" << a << "\n" << b << "\n";
        else cout << "NO\n";
    }


}
