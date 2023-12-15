#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char op[2],op1[2],op2[3],res[5];
    int flag;
}a[10];
int n;
int main()
{
    printf("enter the no.of expression: ");
    scanf("%d",&n);
    printf("enter the expressions\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].op);
        scanf("%s",a[i].op1);
        scanf("%s",a[i].op2);
        scanf("%s",a[i].res);
        a[i].flag=0;
    }
    int res;
    for(int i=0;i<n;i++)
    {
        if( ( isdigit(a[i].op1[0])==1 && isdigit(a[i].op2[0])==1 ) || strcmp(a[i].op,"=")==0 )
        {
            switch(a[i].op[0])
            {
                case '+' : res=atoi(a[i].op1)+atoi(a[i].op2);break;
                case '-' : res=atoi(a[i].op1)-atoi(a[i].op2);break;
                case '*' : res=atoi(a[i].op1)*atoi(a[i].op2);break;
                case '/' : res=atoi(a[i].op1)/atoi(a[i].op2);break;
                case '=' : res=atoi(a[i].op1);break;
            }
            a[i].flag=1;
            char cons[10];
            sprintf(cons,"%d",res);
            for(int j=i+1;j<n;j++)
            {
                if(strcmp(a[j].op1,a[i].res)==0)
                    strcpy(a[j].op1,cons);
            
                else if(strcmp(a[j].op2,a[i].res)==0)
                    strcpy(a[j].op2,cons);            
            }
        }
    }
    printf("optimized code is\n");
    for(int i=0;i<n;i++)
    {
        if(a[i].flag==0)
        {
            printf("%s %s %s %s\n",a[i].op,a[i].op1,a[i].op2,a[i].res);
        }
    }
}
