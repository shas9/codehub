#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int participant;
	long long int region;

	cin >> participant;
	cin >> region;

	long long int i, j, k, l, m, n;

	vector < string > name[region + 10];
	vector < long long int > num[region + 10];

	vector < long long int > sorted;

	long long int max1;
	long long int max2;
	long long int max3;

	string input;
	long long int score;
	long long int reg;

	long long int length;

	long long int flag;

	for(i = 0; i < region + 10; i++)
    {
        name[i].clear();
        num[i].clear();
    }

	for(i = 0; i < participant; i++)
	{
		cin >> input;
		cin >> reg;
		cin >> score;

		name[reg].push_back( input );
		num[reg].push_back( score );
	}



	for(i = 1; i <= region; i++)
	{
		sorted.clear();

		sorted = num[i];

		length = sorted.size();

		sort(sorted.begin(), sorted.end());

		max1 = sorted[length - 1];
		max2 = sorted[length - 2];
		if(length > 2)
		{
			max3 = sorted[length - 3];
		}
		else
		{
			max3  = 0;
		}

		if(max2 == max3)
		{
			if(length > 2)
            {
                printf("?\n");
            }
            else
            {
                cout << name[i][0] << " " << name[i][1] << endl;
            }
		}
		else
		{
		    flag = 0;
			if(max1 == max2)
			{
				for(j = 0; j < length; j++)
				{
					if(max1 == num[i][j])
					{
						cout << name[i][j];
						if(flag == 0)
                        {
                        printf(" ");
                        flag = 1;
                        }
					}

				}
				printf("\n");
			}
			else
			{
				for(j = 0; j < length; j++)
				{
					if(max1 == num[i][j])
					{
						cout << name[i][j] << " ";
						break;
					}
				}
				for(j = 0; j < length; j++)
				{
					if(max2 == num[i][j])
					{
						cout << name[i][j] << endl;
						break;
					}
				}
			}
		}
		name[i].clear();
		num[i].clear();
	}

	return 0;
}
