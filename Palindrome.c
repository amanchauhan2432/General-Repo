#include<stdio.h>
#include<string.h>
void main()
{
    char S1[10],S2[10];
    int i;
    scanf("%s",S1);
    strcpy(S2,S1);
    strrev(S2);
    i=strcmp(S1,S2);
    if(i==0)
        printf("String Is Palindrome");
    else
        printf("String Is Not Palindrome");

}
