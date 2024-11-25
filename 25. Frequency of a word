%{
#include<stdio.h>
#include<string.h>
char word [] = "Best";
int count = 0;
%}
%%
[a-zA-Z]+ {if(strcmp(yytext,word)==0) count++;}
. ;
%%
int yywrap()
{
return 1;
}
int main()
{
extern FILE *yyin, *yyout;
yyin=fopen("input1.txt","r");
yylex();
printf("%d", count);
}
