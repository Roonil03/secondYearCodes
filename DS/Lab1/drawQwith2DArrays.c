#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the length of side: ");
    scanf("%d",&n);
    int p = n;
    n += ((n-1)/2);
    int lengthOfLine = n - p;
    char (*pattern)[n][n] = malloc(sizeof *pattern);
    int i,j;
    for(i=0;i<p;i++)
    {
        for(j=0;j<p;j++)
        {
            if(i==0||j==0||i==p-1 || j == p-1)
            {
                (*pattern)[i][j] = '*';
            }
            else{
                (*pattern)[i][j] = ' ';
            }
        }
    }
    for(i=p,j=lengthOfLine;i>lengthOfLine;i--,j--)
    {
        (*pattern)[p-j-1][p-j-1] = '*';
        (*pattern)[p+j][p+j] = '*';
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c ",(*pattern)[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
