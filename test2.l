STRING      \"([^\"\n]|\\\")*\"


%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_number = 1;
int column = 0;
%}

%%
{STRING}      { column += yyleng; printf("第%d行: 识别到字符串: %s\n", line_number, yytext); yylval.sval = strdup(yytext); return STRING_LITERAL; }
%%