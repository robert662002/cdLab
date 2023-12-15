/*Definition Section*/
%{
#include<stdio.h>
%}


/*Rule Section*/

%%
\/\/(.*) {};					
\/\*(.*\n)*.*\*\/  {};			
%%

/*call the yywrap function*/




/*Auxiliary function*/
/*Driver function*/

int main()
{
yyin=fopen("input6.c","r");
yyout=fopen("out.c","w");
/*call the yylex function.*/
yylex();
return 0;
}
