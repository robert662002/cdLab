#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE *fp;
char c;
char result[100];
int state = 0;
int i=0;

int isop(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' )
        return 1;
    return 0;
}
int issym(char c)
{
    if(c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || c == ';' )
        return 1;
    return 0;
}
void reset()
{
    strcpy(result,"");
    i=0;
    state=0;
    fseek(fp,-1,SEEK_CUR);
}
int iskey(char *result)
{
    if( !strcmp("void",result) ||  !strcmp("main",result) ||  !strcmp("int",result) )
        return 1;
    return 0;
}
int main()
{
    fp = fopen("input.txt", "r");
    while ((c = fgetc(fp)) != EOF)
    {
        result[i++] = c;
        switch (state)
        {
            case 0:
                if (isdigit(c))
                    state = 1;
                else if (isalpha(c))
                    state = 2;
                else if (isop(c))
                    state = 3;
                else if (issym(c))
                    state = 4;
                else if (isspace(c))
                    i = 0;
                break;
            case 1:
                if(!isdigit(c))
                {
                    result[i-1]='\0';
                    printf("%s ->Number\n",result);
                    reset();
                }
                break;
            case 2:
                if(!isalnum(c))
                {
                    result[i-1]='\0';
                    if(iskey(result))
                        printf("%s ->Keyword\n",result);
                    else
                        printf("%s ->Identifier\n",result);
                    reset();
                }
                break;
            case 3:
                if(!isop(c))
                {
                    result[i-1]='\0';
                    printf("%s ->Operator\n",result);
                    reset();
                }
                break;
            case 4:
                if(!issym(c))
                {
                    result[i-1]='\0';
                    printf("%s ->Symbol\n",result);
                    reset();
                }
                break;
        }
    }
    fclose(fp);
}