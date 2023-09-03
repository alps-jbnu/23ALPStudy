#include <stdio.h>

int main(void)
{
   int arr[9];
   int i, max, idx;
   max=idx=0;

   for(i=0; i<9; i++)
   {
       scanf("%d", &arr[i]);

        if(max<arr[i])
        {
            max=arr[i];
            idx=i;
        }
   }

    printf("%d\n%d", max, idx+1);

    return 0;
}