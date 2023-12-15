#include<stdio.h>
#include<string.h>
char input[20][20]={"E=TA","A=+TA","A=e","T=FT","B=*FB","B=e","F=i","F=(E)"};
char first[5];
int np=8;
int m=0;

int isTerminal(char c)
{
    if ( c == 'e' || c == '+' || c == '*' || c == ')' || c == '(' || c=='i')
        return 1;
    return 0;
}

void findFirst(char c)
{
    if(isTerminal(c))
    {   
        first[m++]=c;
        return ;
    }
    for(int row=0;row<np;row++)
        if(input[row][0]==c) 
            findFirst(input[row][2]);
}
int main()
{
    int flag=1;
    char c,ch;
    while(flag)
    {
        printf("Enter the character: ");
        scanf("%c%c",&c,&ch);
        findFirst(c);
        printf("The first of %c is : { ",c);
        for(int i=0;i<m;i++)
            printf("%c ",first[i]);
        printf("}\n");
        m=0;
        strcpy(first,"");
        printf("\nIf you want to continue 0/1: ");
        scanf("%d%c",&flag,&ch);
    }
}