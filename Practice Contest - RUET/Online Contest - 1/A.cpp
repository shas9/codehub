#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

using namespace std;

int main()
{

    ll i, j, k, l, m, n, o, p;


    bool isPrime[1000001];

    isPrime[0]=false;
    isPrime[1]=false;

    for(i=2; i<1000001; i++)
    {
        isPrime[i]=true;
    }

    for(i = 2; i < 1000001; i++)
    {
        if(isPrime[i] == true)
        {
            for(j=2; i*j < 1000001; j++)
            {
                isPrime[i*j]=false;
            }
        }
    }


    cin >> n;
    long long int ar[n];
    for(int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    int number;
    for(i=0; i<n; i++)
    {
        number =sqrt(ar[i]);
        if(number-sqrt(ar[i])==0)
        {
            if(isPrime[number])
                cout << "YES" << endl;
            else
                cout <<   "NO" << endl;
        }
        else
			cout <<   "NO" << endl;
    }
    return 0;
}
