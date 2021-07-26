#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcase;

	map < string, int > trees;

	set < string > name;

	string index;

	string input;

	int count;
	int temp;
	double percentage;

	int i, j, k, l;

	string extra;

	cin >> testcase;
	getline(cin, extra); //testcase enter-er somoykar enter khacche
	set < string > :: iterator it;

	getline(cin, extra); //test case-er porer extra blank line khacche

	for(i = 0; i < testcase; i++)
	{
		count = 0;
		trees.clear();
		name.clear();

		//cin >> extra;

		if(i != 0)
        {
            printf("\n");
        }
		while(1)
		{
			input.clear();

			if (!getline(cin,input)) //getline returning 0 means it's EOF
				break;

			if (input.size() == 0) //blank line mane ei test case shesh
				break;

			//cout << "Input is " << input << endl;
		    input = extra + input;
		    //cout << extra << endl;
			count++;

			name.insert( input );
			trees[input]++;
		}
		//cout << count << endl;

		for(it = name.begin(); it != name.end(); it++)
		{
 			index = *it;
			//cout << trees[index] << endl;
			temp = trees[index];
			percentage = (temp * 100 * 1.0) / count;
			cout <<  index;
			printf(" %.4lf\n", percentage);
		}
		//printf("\n");

		//cout << "HERE I is: " << i << endl;
	}

	return 0;
}
