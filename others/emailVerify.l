%{
    #include<stdio.h>
    int flag=0;
%}

%%

[a-zA-Z0-9]+"@"[a-zA-Z0-9]+"."[a-zA-Z0-9]+ {flag = 1;}
. ;

%%

void main()
{
    printf("enter a string: ");
    yylex();
    if (flag==1)
        printf("\nvalid\n");
    else
        printf("\ninvalid\n");
}
int yywrap()
{
    return 1;
}