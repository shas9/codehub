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

        size = input.size();

        for(j = 0; j < size; j++)
        {
            if(input[j] >= 'A' && input[j] <= 'Z')
            {
                input[j] = input[j] + (97 -65);
            }
            else
            {
                input[j] = input[j] - (97 -65);
            }
        }

        cout << input << endl;
    }
}
