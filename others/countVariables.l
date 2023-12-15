%{
#include <stdio.h>

int int_count = 0;
int float_count = 0;
int char_count = 0;
%}

%%
int+[a-zA-Z_][a-zA-Z0-9_]*   { int_count++; }
float\s+[a-zA-Z_][a-zA-Z0-9_]* { float_count++; }
char\s+[a-zA-Z_][a-zA-Z0-9_]*  { char_count++; }
.                             ;
%%

int main() {
    yyin = fopen("input.c","r");
    yylex();
    printf("Integer Variables: %d\n", int_count);
    printf("Float Variables: %d\n", float_count);
    printf("Char Variables: %d\n", char_count);
    return 0;
}
int yywrap()
{
    return 1;
}