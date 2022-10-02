#include <stdio.h>

void main()
{
    char s[20];
    gets(s);
    int i=0;
    int n=0;

    while(s[i]!='\0')
    {
        i++;
        n++;
    }
    printf("the lengeth of the string = %d",n);

}