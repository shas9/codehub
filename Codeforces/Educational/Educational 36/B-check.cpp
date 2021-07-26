/*=================================*\

	  Md. Shahidul Islam
		 CSE, BRUR
	  Rangpur, Bangladesh
 mail: shahidul.cse.brur@gmail.com
 FB  : fb.com/shahidul.brur
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English)
\*=================================*/
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

#define sI(a)		  scanf("%d", &a)
#define sL(a)		  scanf("%I64d", &a)
#define sC(a)		  scanf("%c", &a)
#define sS(a)		  scanf("%s", a)
#define sF(a)		  scanf("%f", &a)
#define sD(a)		  scanf("%lf", &a)

#define sI2(a,b)	  scanf("%d %d", &a, &b)
#define sL2(a,b)	  scanf("%I64d %I64d", &a, &b)
#define sC2(a,b)	  scanf("%c %c", &a, &b)
#define sS2(a,b)	  scanf("%s %s", a, b)
#define sF2(a,b)	  scanf("%f %f", &a, &b)
#define sD2(a,b)	  scanf("%lf %lf", &a, &b)

#define sI3(a,b,c)	  scanf("%d %d %d", &a, &b, &c)
#define sL3(a,b,c)	  scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sC3(a,b,c)	  scanf("%c %c %c", &a, &b, &c)
#define sS3(a,b,c)	  scanf("%s %s %s", a, b, &c)
#define sF3(a,b,c)	  scanf("%f %f %f", &a, &b, &c)
#define sD3(a,b,c)	  scanf("%lf %lf %lf", &a, &b, &c)

#define pI(a)		  printf("%d", a)
#define pL(a)		  printf("%I64d", a)
#define pC(a)		  printf("%c", a)
#define pS(a)		  printf("%s", a)
#define pF(a)		  printf("%f", a)
#define pNL		      printf("\n")

#define pI2(a,b)	  printf("%d %d", a, b)
#define pL2(a,b)	  printf("%I64d %I64d", a, b)
#define pC2(a,b)	  printf("%c %c", a, b)
#define pS2(a,b)	  printf("%s %s", a, b)
#define pF2(a,b)	  printf("%f %f", a, b)

#define pI3(a,b,c)	  printf("%d %d %d", a, b, c)
#define pL3(a,b,c)	  printf("%I64d %I64d %I64d", a, b, c)
#define pC3(a,b,c)	  printf("%c %c %c", a, b, c)
#define pS3(a,b,c)	  printf("%s %s %s", a, b, c)
#define pF3(a,b,c)	  printf("%f %f %f", a, b, c)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MAX = 100002;
int fa[11];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin>>a>>b;
	int la = a.length();
	int lb = b.length();
	sort(all(a));
	reverse(all(a));
	if(la<lb)
	{
		cout << a << "\n";
		return 0;
	}
	string ans;
	f(i, 0, la-1) fa[a[i] - '0']++;
	f(i, 0, lb-1)
	{
		int db = b[i] - '0';
		if(fa[db]>0)
		{
			ans+=(db+'0');
			fa[db]--;
		}
		else
		{
			F(j, db-1, 0)
			{
				if(fa[j]>0)
				{
					ans+=(j+'0');
					fa[j]--;
					F(k, 9, 0)
					{
						while(fa[k]>0)
						{
							ans+=(k+'0');
							fa[k]--;
						}
					}
					cout << ans << "\n";
					return 0;
				}
			}

			string scnd;
			F(j, i-1, 0)
			{
				int d = b[j]-'0';
				fa[d]++;
				F(k, d-1, 0)
				{
					if(fa[k]>0)
					{
						//cout << k << " #\n";
						scnd+=(k+'0');
						fa[k]--;
						F(l, 9, 0)
						{
							while(fa[l]>0)
							{
								scnd+=(l+'0');
								fa[l]--;
							}
						}
						string fst;
						f(l, 0, j-1)
							cout << ans[l];
						cout  << scnd << "\n";
						return 0;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
