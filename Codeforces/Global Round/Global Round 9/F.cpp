// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

vector < pll > vec;

ll ask(ll x)
{
    ll ret;

    cout << x << endl;

    cin >> ret;

    assert(ret != -1);

    if(ret == 0)
    {
        exit(0);
    }

    return ret;
}

bool poss()
{
	vector < pll > tvec = vec;

    sort(vec.begin(),vec.end());

    ll x = vec[1].first - vec[0].first;
    ll y = vec[2].first - vec[1].first;

    vec = tvec;

    if(x == y / 2) return 0;

    if(y == x / 2) return 0;

    return 1;
}

bool poss1(ll add, ll last)
{
	if(vec[0].second == last) return 0;

	vec[0].first += add;

	bool ret = poss();

	if(ret == 0)
	{
		vec[0].first -= add;
		return 0;
	}

	return 1;
}

bool poss2(ll add, ll last)
{
	if(vec[1].second == last) return 0;

	vec[1].first += add;

	bool ret = poss();

	if(ret == 0)
	{
		vec[1].first -= add;
		return 0;
	}

	return 1;
}

bool poss3(ll add, ll last)
{
	if(vec[2].second == last) return 0;

	vec[2].first += add;

	bool ret = poss();

	if(ret == 0)
	{
		vec[2].first -= add;
		return 0;
	}

	return 1;
}

ll stone(ll add, ll last)
{
	sort(vec.begin(),vec.end());

	ll x = vec[1].first - vec[0].first;
    ll y = vec[2].first - vec[1].first;

    if(poss1(add,last)) return vec[0].second;
    if(poss2(add,last)) return vec[1].second;
    if(poss3(add,last)) return vec[2].second;
    else assert(0);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    vec.clear();

    for(ll i = 0; i < 3; i++)
    {
        slld(input);

        vec.push_back({input,i + 1});
    }

    if(poss())
    {
        cout << "Second" << endl;

        ll last = -1;

        cin >> input;

        for(ll i = 1; i <= 2000; i++)
        {
            input = stone(input, last);

            last = input;

//            bug;

            input = ask(input);
        }

    }
    else
    {
        cout << "First" << endl;

        sort(vec.begin(),vec.end());

        ll x = vec[1].first - vec[0].first;
        ll y = vec[2].first - vec[1].first;

        if(x == y / 2)
        {
            while(ask(y));
        }
        else
        {
            while(ask(x));
        }

    }


}



