#include <bits/stdc++.h>`

using namespace std;

int main()
{
    int testcase;
    string input;

    cin >> testcase;

    for(int cs = 1; cs <= testcase; cs++)
    {
        cin >> input;

        if(input == "map")
        {
            cout << "map = map < int, int > mp;" << endl;
        }
        else if(input == "set")
        {
            cout << "set = set < int > st;" << endl;
        }
        else if(input == "vector")
        {
            cout << "vector = vector < int > vec;" << endl;
        }
        else if(input == "stack")
        {
            cout << "stack = stack < int > st;" << endl;
        }
        else if(input == "queue")
        {
            cout << "queue = queue < int > q;" << endl;
        }
        else if(input == "priority_queue")
        {
            cout << "priority_queue = priority_queue < int > q;" << endl;
        }
    }


}

