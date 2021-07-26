            else
            {
                for (i = 2; i < n; i++)
                    grid[2][i] = '#';

                k -= n-2;

                ll l = 2, r = n-1;

                while (l < r && k)
                {
                    grid[3][l] = grid[3][r] = '#';
                    l++;
                    r--;
                    k -= 2;
                }
            }
        }
        else
        {
            for (i = 2; i < n && k; i++)
            {
                for (j = 2; j <= 3 && k; j++)
                {
                    grid[j][i] = '#';
                    k--;
                }
            }
        }

        printf("YES\n");

        for (i = 1; i <= 4; i++)
        {
            for (j = 1; j <= n; j++)
                printf("%c", grid[i][j]);
            printf("\n");
        }
    }

    return 0;
}
