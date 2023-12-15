%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%

[A-z]+  {
            printf("\ninvalid input\n");
            return 0;
        }
[0-9]+  {

                int num=atoi(yytext);
                int dup=num;
                int rev=0,dig;
                while(num>0)
                {
                    dig=num%10;
                    rev=rev*10+dig;
                    num/=10;
                }
                if(dup==rev)
                    printf("\npalidrome\n");
                else
                    printf("\nnot a palindrom\n");
                return 0;
        }
.       {
                printf("\ninvalid input\n");
                return 0;
        } 
%%

int main()
{
    printf("enter a number: ");
    yylex();
}