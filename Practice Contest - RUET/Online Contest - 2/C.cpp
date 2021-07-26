
#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld ", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)



using namespace std;

long long int binarysearch(vector < long long int > array, long long int size, long long int number)
{
	long long int position;
	long long int high, mid, low;

	high = size;
	low = 0;
	mid = (high + low) / 2;

	while(low < high)
	{
		if(number == array[mid])
		{
			position = mid;
			break;
		}
		else if(number > array[mid])
		{
			low = mid + 1;
			mid = (high + low) / 2;
		}
		else if(number < array[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
	}

	if(low >= high)
	{
		position == 0;
	}

	return position;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    vector < long long int > a;
    vector < long long int > b;

    ll sizea, sizeb;

    ll input;


    scanlld(sizea);
    scanlld(sizeb);

    a.clear();
    b.clear();

    for(i = 1; i  <= sizea; i++)
    {
        scanlld(input);

        a.push_back(input);
    }

    for(i = 1; i  <= sizeb; i++)
    {
        scanlld(input);

        b.push_back(input);
    }

    sort(a.begin(), a.end());

    for(i = 0; i  < sizeb; i++)
    {
        input = b[i];

        ll pos;

        pos = binarysearch(a,sizea,input);

        printlld(pos);
    }
    printnewline;


}

