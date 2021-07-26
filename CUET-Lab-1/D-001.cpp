#include <bits/stdc++.h>

using namespace std;

int main()
{
	int size;

	int temp;
	int tag;

	vector < int > normie;
	vector < int > sorted;

	int i, j, k, l;

	int input;

	int flip;

	int testcase;

	cin >> testcase;

	int x;

	for(x = 1; x <= testcase; x++)
	{
		cin >> size;

			flip = 0;
			for(i = 0; i < size; i++)
			{
				cin >> input;
				normie.push_back( input );
			}

			sorted = normie;

			sort(sorted.begin(), sorted.end());

			if(sorted == normie)
			{
				flip = 0;
			}
			else
			{
	            for(i=0;i< size - 1;i++)
	            {
	                for(j=i+1;j<size;j++)
	                {
	                    if(normie[i]>normie[j])
	                    {
	                        flip++;
	                    }
	                }

	            }

			}

			printf("Optimal train swapping takes %d swaps.\n", flip);
			normie.clear();

	}

}


