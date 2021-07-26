#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcase;
	string flag;
	string zero = "0";
	//bool val;

	cin >> testcase;

	int i, j, k, l, m, n;

	int input;

	string binary;
	//string ex;

	int temp;
	string rem;

	long long output;

	for(i = 1; i <= testcase; i++)
	{
		cin >> input;

		temp = input;

		while(temp != 1)
		{
			rem = (temp % 2) + 48;

			binary = rem + binary;
			temp = temp / 2;

		}

		rem = 49;

		binary = rem + binary;

		flag = binary;
		//cout << binary << endl;

		while(1)
        {
            bool val = next_permutation(binary.begin(), binary.end());
            if (val == false)
            {
                //cout << "fuuuuuu" << endl;
                binary = zero + flag;
                flag = binary;
                //cout << binary << endl;

            }
            else
            {
                //cout << binary << endl;
                break;
            }
        }

		//cout << binary << endl;
		int size;

		size = binary.size();

		output = 0;

		for(j = 0; j < size; j++)
		{
			if(binary[size-1-j] == '1')
			{
				output = output + pow(2, j);
			}
		}

		printf("Case %d: %lld\n", i, output);

		binary.clear();


	}

	return 0;
}
