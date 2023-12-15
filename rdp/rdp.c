#include<stdio.h>
#include<string.h>
int error=0,i=0;
char str[10];
void E();
void EP();
void T();
void TP();
void F();

void E()
{
    T();
    EP();
}
void T()
{
    F();
    TP();
}
void EP()
{
    if (str[i]=='+')
    {
        i++;
        T();
        EP();
    }
}
void TP()
{
    if( str[i]=='*')
    {
        i++;
        F();
        TP();
    }
}

void F()
{
    if(str[i]=='(')
    {
        i++;
        E();
        if(str[i]==')')
            i++;
        else  
            error=1;
    }
    else if(str[i]=='i' && str[i+1]=='d')
        i+=2;
    else
        error=1;
}
int main()
{
    printf("E->TE'\nT->FT'\nE'->+TE'\nT'->*FT'\nF->id|(E)\n");
    printf("Enter the expression:\n");
    scanf("%s",str);
    E();
    if( i == strlen(str) && error==0 )
        printf("accepted\n");
    else
        printf("not accepted");
    return 0;
}