#include<stdio.h>
#include<string.h>
int flag=0;
int top=0;
int ip=0;
char stack[100]="$",prev[100]="$";
char input[20];
char precedence[4][4] = {
    /*       i    +    *    $  */
    /* i */ '=', '>', '>', '>',
    /* + */ '<', '>', '<', '>',
    /* * */ '<', '>', '>', '>',
    /* $ */ '<', '<', '<', 'A'};
char terminal[4] = {'i', '+', '*', '$'};

void shift()
{
    top++;
    stack[top]=input[ip];
    ip++;
}

void reduce()
{
    if(stack[top]=='E' && (stack[top-1]=='+' || stack[top-1]=='*') && stack[top]=='E')
        top-=2;
    else if(stack[top]=='i')
        stack[top]='E';
    else
        flag=3;
}
void printS(char pre)
{
    for(int i=0;i<=top;i++)
        printf("%c",stack[i]);
    printf("\t");
    for(int i=ip;i<strlen(input);i++)
        printf("%c",input[i]);
    printf("\t");
    if(pre=='A')
        printf("Accept\n");
    else if(pre=='I')
        printf("Invalid\n");
    else if(pre=='>')
        printf("reduce\n");
    else
        printf("shift\n");
}

void opp()
{
    while(1)
    {
        int r,c;
        if(stack[top]=='E')
        {
            top--;
            flag=1;
        }
        for(r=0;r<4;r++)
            if(terminal[r]==stack[top])
                break;
        for(c=0;c<4;c++)
            if(terminal[c]==input[ip])
                break;
        if(flag==1)
        {
            top++;
            flag=0;
        }
        if (r==4 || c==4)
        {
            flag=2;
            printS('I');
            break;
        }
        else
            printS(precedence[r][c]);
        if(precedence[r][c]=='A')
        {
            flag=1;
            break;
        }
        if(precedence[r][c]=='<' || precedence[r][c]=='=')
            shift();
        else if(precedence[r][c]=='>')
        {
            reduce();
            if(flag==3)
                break;
        }
        if(strcmp(stack,prev)==0)
        {
            flag=3;
            break;
        }
        else
            strcpy(prev,stack);
    }
    if(flag==1)
        printf("accedpted");
    else
        printf("not accepted flag=%d",flag);
}
int main()
{
    printf("enter the string: ");
    scanf("%s",input);
    opp();
}