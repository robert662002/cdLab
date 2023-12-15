%{
#include <stdio.h>

int count_0 = 0;
int count_1 = 0;

void yyerror(const char* s);

%}

%token zero one
%token EOL

%%

string: /* empty */
    | string zero { count_0++; }
    | string one { count_1++; }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    if (count_0 == count_1) {
        printf("String is valid with equal number of 0s and 1s.\n");
    } else {
        printf("String is not valid. Unequal number of 0s and 1s.\n");
    }
    return 0;
}