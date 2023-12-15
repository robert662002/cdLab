%{

	#include<stdio.h>

	int vowel=0,consonant=0;

%}

%%

[a|e|i|o|u|A|E|I|O|U] {vowel++;}

[a-z|A-Z] {consonant++;}

%%

void main()

{

	yyin=fopen("data1.txt","r");

	yylex();

	printf("Number of vowels: %d\n",vowel);

	printf("Number of consonents: %d\n",consonant);

}

int yywrap()
{
    return 1;
}