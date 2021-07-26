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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > vec, svec;
vector < ll > seq;

void prn()
{
	for(auto it: vec) cout << it << " ";

	cout << endl;
}

bool solve(ll idx)
{
	ll num = svec[idx];
	ll pos;

	for(ll i = idx; i < vec.size(); i++)
	{
		if(vec[i] == num)
		{
			pos = i;
			break;
		}
	}

	while(abs(pos - idx) > 2)
	{
////		cout << pos << " " << idx << "\n";
//		prn();
		swap(vec[pos], vec[pos - 1]);
		swap(vec[pos - 1], vec[pos - 2]);

		pos -= 2;

		seq.push_back(pos);
	}

//	prn();

	if(abs(pos - idx) == 2)
	{
		swap(vec[pos], vec[pos - 1]);
		swap(vec[pos - 1], vec[pos - 2]);

		seq.push_back(idx);
	}
	else if(abs(pos - idx) == 1)
	{
		swap(vec[pos], vec[pos + 1]);
		swap(vec[pos - 1], vec[pos]);

		seq.push_back(idx);

//		prn();

		pos++;

		swap(vec[pos], vec[pos - 1]);
		swap(vec[pos - 1], vec[pos - 2]);

		seq.push_back(idx);
	}
}

bool lasttry()
{
	if(vec.size() < 4) return 1;

	if(vec[vec.size() - 3] == vec[vec.size() - 4])
	{
		seq.push_back(vec.size() - 4);
		seq.push_back(vec.size() - 4);
		seq.push_back(vec.size() - 3);
		seq.push_back(vec.size() - 3);

		return 0;
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		vec.clear();

		slld(n);

		for(ll i = 0; i < n; i++)
		{
			slld(input);
			vec.push_back(input);
		}

		svec = vec;

		sort(svec.begin(),svec.end());

		seq.clear();


		for(ll i = 0; i < (n - 2); i++)
		{

//			cout << i << endl;

			solve(i);

			prn();
		}

		if(vec != svec)
		{
			if(lasttry())
			{
				printf("-1\n");
				continue;
			}
		}

		cout << seq.size() << '\n';

		for(auto it: seq) printf("%lld ", it + 1);

		cout << '\n';
    }


}



