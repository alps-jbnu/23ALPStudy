#include <stdio.h>

int main()
{
    int n1,n2,n3,num,count;
    
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    
    char str[50];
    num=n1*n2*n3;
    sprintf(str,"%d",num); //정수값을 str에 문자열로 입력
    
    for(int i=0;i<=9;i++){ //0~9
        count=0;
        for(int j=0;str[j]!=0;j++) //'\0'==null
        { 
            if((str[j]-48)==i)
                count++;
        }
        printf("%d\n",count);
    }
}
