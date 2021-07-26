#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define printnewline printf("\n")

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

using namespace std;

long long int counttwo(long long int Num)
{
	long long int ans, twos, flag;

	twos = 1;
	ans = 0;
	while(1)
	{
		flag = (Num / pow(2,twos));

		if(flag == 0)
		{
			return ans;
		}

		ans = ans + flag;
		twos++;
	}
}
long long int countfive(long long int Num)
{
	long long int ans, fives, flag;

	fives = 1;
	ans = 0;
	while(1)
	{
		flag = (Num / pow(5,fives));

		if(flag == 0)
		{
			return ans;
		}

		ans = ans + flag;
		fives++;
	}
}

long long int normaltwo(long long int num)
{
	long long int count, flag;

	count = 0;

	while(num % 2 == 0)
	{
		count++;
		num = num / 2;
	}

	return count;
}

long long int normalfive(long long int num)
{
	long long int count, flag;

	count = 0;

	while(num % 5 == 0)
	{
		count++;
		num = num / 5;
	}

	return count;
}

int main()
{
    long long int i, j, k, l, m;
    long long int testcase;

    scanlld(testcase);

    long long int n, r, p, q, ans, two1, two2, five1, five2, flag, tag;

    long long int totaltwo, totalfive;

    for(i = 1; i <= testcase; i++)
    {
    	scanlld(n);
    	scanlld(r);
    	scanlld(p);
    	scanlld(q);

    	two1 = counttwo(n) - (counttwo(r) + counttwo(n - r));
    	five1 = countfive(n) - (countfive(r) + countfive(n - r));

    	two2 = (normaltwo(p)) * q;
    	five2 = (normalfive(p)) * q;

    	totalfive = five2 + five1;
    	totaltwo = two2 + two1;

    	//printf("two1 = %lld, two2 = %lld, total two = %lld\nfive1 = %lld, five2 = %lld, totalfive = %lld\n", two1, two2, totaltwo, five1, five2, totalfive);

    	if(totaltwo >= totalfive)
    	{
    		ans = totalfive;
    	}
    	else
    	{
    		ans = totaltwo;
    	}

    	printcase(i,ans);
    }

    return 0;


}


