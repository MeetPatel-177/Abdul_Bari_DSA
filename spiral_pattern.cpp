#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    if (row == 1 && col == 1)
    {
        printf("1");
    }
    else if (row == 1 && col == 2)
    {
        printf("2");
    }
    else if (row == 2 && col == 2)
    {
        printf("3");
    }
    else if (row == 2 && col == 1)
    {
        printf("4");
    }
    else
    {
        int num = 4;
        int r = 2, c = 1;
        int nextr = 2, nextc = 1;
        int found = 0;
        while (1)
        {
            r++;
            num++;
            if (r == row && c == col)
            {
                printf("%d", num);
                found = 1;
                break;
            }

            nextc += 2;
            while (c < nextc)
            {
                c++;
                num++;
                if (r == row && c == col)
                {
                    printf("%d", num);
                    found = 1;
                    break;
                }
            }
            if (found)
                break;

            while (r > 1)
            {
                r--;
                num++;
                if (r == row && c == col)
                {
                    printf("%d", num);
                    found = 1;
                    break;
                }
            }
            if (found)
                break;

            c++;
            num++;
            if (r == row && c == col)
            {
                printf("%d", num);
                found = 1;
                break;
            }

            nextr += 2;
            while (r < nextr)
            {
                r++;
                num++;
                if (r == row && c == col)
                {
                    printf("%d", num);
                    found = 1;
                    break;
                }
            }
            if (found)
                break;

            while (c > 1)
            {
                c--;
                num++;
                if (r == row && c == col)
                {
                    printf("%d", num);
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
    }
    return 0;
}