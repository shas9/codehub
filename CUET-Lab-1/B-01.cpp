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

	while(cin >> size)
	{
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
			/*for(j = 0; j < normie.size(); j++)
			{
				if(normie[j] != sorted[j])
				{
				    //printf("DBUG normie[%d] == %d\nflip =%d\n", j, normie[j],flip);
					flip++;

					tag = normie[j];
					for(k = 0; k < size; k++)
                    {
                        if(sorted[k] == tag)
                        {
                            break;
                        }
                    }
                    temp = normie[k];
                    normie[j] = temp;
                    normie[k] = tag;
				}
			}*/

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

		printf("Minimum exchange operations : %d\n", flip);
		normie.clear();
	}

}

