%{
#include "y.tab.h"
%}

%%
0       { yylval = 0; return zero; }
1       { yylval = 1; return one; }
\n      { return EOL; }
.       { return yytext[0]; }
%%

int yywrap() {
    return 1;
}