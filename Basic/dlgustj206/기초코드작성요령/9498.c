#include <stdio.h>

int main(void)
{
    int s;
    scanf("%d", &s);
    
    if(s>=90)
        printf("A\n");
    else if(s>=80&&s<90)
        printf("B\n");
    else if(s>=70&&s<80)
        printf("C\n");
    else if(s>=60&&s<70)
        printf("D\n");
    else
        printf("F\n");
    
    return 0;
}