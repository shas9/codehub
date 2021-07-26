			#include <bits/stdc++.h>`

			#define slld(longvalue) scanf("%lld", &longvalue)

			#define ll long long
			#define ull unsigned long long
			#define pll pair < long long, long long >

			#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

			ll arr[4003];
			string str;
			map < ll, ll > mp;

			int main()
			{
				ll i, j, k, l, m, n, o, r, q;
				ll testcase;
				ll input, flag, tag, ans;

			//    freopen("input.txt", "r", stdin);

			//    freopen("output.txt", "w", stdout);

				while(cin >> n >> str)
				{
					ll idx = 0;
					ll zero = 0;

					for(auto it: str)
					{
						arr[++idx] = (it - '0');
					}


					for(i = 1; i <= idx; i++)
					{
						ll sum = 0;

						for(j = i; j <= idx; j++)
						{
							sum += arr[j];

							mp[sum]++;
						}
					}

					if(n == 0)
					{
						zero = mp[0];

						ans = (zero * idx * (idx + 1)) - (zero * zero);

						printf("%lld\n", ans);

						continue;
					}

					ans = 0;

					for(i = 1; i <= idx; i++)
					{
						ll sum = 0;

						for(j = i; j <= idx; j++)
						{
							sum += arr[j];

							if(sum == 0) continue;

							if(n % sum) continue;

							m = (n / sum);

							ans += mp[m];

			//				if(m == sum) ans--;
						}
					}

					printf("%lld\n", ans);
				}


			}


