#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcase;
    int i, j, k, l;

    string input;

    int size;

    cin >> testcase;

    for(i = 0; i < testcase; i++)
    {
        cin >> input;
        cin >> size;

        for(j = 0; j < size; j++)
        {
            if(input[j] == 57)
            {
                size++;
            }
            else
            {
                input[j] = 57;
            }
        }

        printf("Case %d: ", i + 1);
        cout << input << endl;
    }
}
