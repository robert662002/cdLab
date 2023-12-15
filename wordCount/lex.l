%{
#include<stdio.h>
int words=0;
%}

%%
[a-zA-Z]+[,. \t] {words++;printf("\n%s",yytext);}
. {}
%%

void main()
{
yyin=fopen("text.txt", "r");
yylex();
printf(" Total count of Words: %d\n", words);
}

int yywrap() {}