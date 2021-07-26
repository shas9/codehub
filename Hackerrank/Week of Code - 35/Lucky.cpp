#include <bits/stdc++.h>

#define bug printf("BUG\n")

using namespace std;

int main()
{
    long long int i, j, k, l, m, n, o;
    long long int testcase;
    long long int input, flag, tag;

    string ansname;
    long long int minimum = 9999999999;
    long long int minusone = 0;
    string name;
    long long int four;
    long long int seven;

    scanf("%lld", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        cin >> name;
        scanf("%lld", &input);
        four = 0;
        seven = 0;

        long long int temp = input;
        flag = 1;

        while(temp > 0)
        {
            tag = temp % 10;
            temp /= 10;

            if(tag == 4)
            {
                four++;
            }
            else if(tag == 7)
            {
                seven++;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if(flag && four == seven)
        {
            minusone = 1;
            if(input < minimum)
            {
                ansname = name;
                minimum = input;
            }
        }
    }

    if(minusone)
    {
        cout << ansname << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;


}


