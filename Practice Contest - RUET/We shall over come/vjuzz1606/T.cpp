#include <bits/stdc++.h>

using namespace std;

int main()
{
    string command;
    vector < int > value;
    vector < int > inst;
    vector < int > sorted;
    vector < int > initial;

    map < int, int > store;

    int inst2;
    int i, j, k, l, m;

    int input;
    int input2;
    int ln;
    ln = 0;

    while(1)
    {
        cin >> command;

        if(command == "#")
        {
            break;
        }

        cin >> input;

        inst.push_back( input );
        cin >> input2;
        store[input] = input2;
    }

    ln = inst.size();

    sort(inst.begin(), inst.end());

    for(i = 0; i < ln; i++)
    {
        j = inst[i];
        k = store[j];
        value.push_back( k );
        //cout << j << endl << k << endl;
    }

    cin >> inst2;


    initial = value;

    //printf("---\n");

    for(i = 0; i < inst2; i++)
    {
        sorted = value;
        sort(sorted.begin(), sorted.end());
        j = sorted[0];

        for(k = 0; k < ln; k++)
        {
            if(j == value[k])
            {
                cout << inst[k] << endl;
                value[k] = value[k] + initial[k];
                break;
            }
        }

    }

    return 0;
}
