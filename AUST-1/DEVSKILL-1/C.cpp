#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcase;
    int i, j, k, l;

    string input;

    int size;

    cin >> testcase;

    int count;

    for(i = 1; i <= testcase; i++)
    {
        cin >> input;

        size = input.size();

        count = 0;

        for(j = 0; j < size; j++)
        {
            if(input[j] >= 48 && input[j] <= 57)
            {
                k = input[j] - 48;
                count = count + k;
            }
        }
        k = count % 3;

        l = 3 - k;

        printf("Case %d: %d\n", i, l);
    }
    return 0;
}
