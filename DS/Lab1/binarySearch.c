#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("%d",a[i]);
    int ar[] = {1,2,3,4,5,6,7,8,9,10};
    int i,m;
    int min = 0, max = sizeof(ar)/sizeof(ar[0]);
    scanf("%d",&m);
    while(1)
    {
        int half = (max+min)/2;
        if(m == ar[half])
        {
            printf("Element %d found at %d",m,half);
            break;
        }
        if(m>ar[half])
        {
            min = half;
        }
        else{
            max = half;
        }
    }
    return EXIT_SUCCESS;
}
