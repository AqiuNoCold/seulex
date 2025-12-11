/* __SEULEX_PROLOG_BEGIN__ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylineno = 1;
FILE *yyin = NULL;
FILE *yyout = NULL;

char yytext[1024] = "";
int yyleng = 0;

static int input(void) {
    int c = fgetc(yyin ? yyin : stdin);
    if (c == '\n') yylineno++;
    return c;
}

static void yyunput(int c) {
    if (c == '\n') yylineno--;
    ungetc(c, yyin ? yyin : stdin);
}

#define ECHO fwrite(yytext, 1, yyleng, yyout ? yyout : stdout)
/* __SEULEX_PROLOG_END__ */

#include "minic.tab.h"
#include <stdlib.h>
extern int Lineno;
extern int yylineno;

int ConvertHexToint(char* str) {
    return (int)strtol(str, NULL, 16);
}


int yywrap() {
    return 1;
}
/* __SEULEX_YYLEX_BEGIN__ */
int yylex() {
    int state = 0;
    int ch;
    yyleng = 0;
    memset(yytext, 0, sizeof(yytext));

    while (1) {
        ch = input();
        if (ch == EOF) {
            if (yyleng > 0) { 
                // EOF 之前还有未处理的字符，回退并尝试匹配
                // 这里简化处理，通常意味着最后一部分匹配失败或结束
            }
            return YYEOF;
        }

        switch(state) {
            case 0:
                switch(ch) {
                    case '\t':
                        state = 46;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '\n':
                        state = 46;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '\x0B':
                        state = 46;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '\r':
                        state = 46;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case ' ':
                        state = 46;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '!':
                        state = 72;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '$':
                        state = 47;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '%':
                        state = 48;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '&':
                        state = 1;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '(':
                        state = 49;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case ')':
                        state = 50;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '*':
                        state = 51;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '+':
                        state = 52;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case ',':
                        state = 53;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '-':
                        state = 54;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '/':
                        state = 55;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '0':
                        state = 40;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case ';':
                        state = 56;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '<':
                        state = 42;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '=':
                        state = 44;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '>':
                        state = 43;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '[':
                        state = 57;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case ']':
                        state = 58;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '^':
                        state = 59;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 17;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 12;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 23;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 35;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 15;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 21;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 19;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '{':
                        state = 60;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '|':
                        state = 45;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '}':
                        state = 61;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '~':
                        state = 62;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        printf("Lexical error: unexpected char '%c'\n", ch);
                        return -1;
                        break;
                }
                break;
            case 1:
                switch(ch) {
                    case '&':
                        state = 63;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return '&'; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 2:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return BREAK; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 3:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return CONTINUE; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 4:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return ELSE; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 5:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return IF; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 6:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return INT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 7:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return RETURN; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 8:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return VOID; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 9:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return WHILE; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 10:
                switch(ch) {
                    case '0':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return HEXNUM; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 11:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 12:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 13;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 13:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 14;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 14:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 18;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 15:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 16;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 16:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 20;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 17:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 25;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 18:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 22;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 19:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 24;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 20:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 28;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 21:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 30;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 22:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 26;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 23:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 27;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 24:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 29;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 25:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 31;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 26:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 36;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 27:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 37;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 28:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 33;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 29:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 38;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 30:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 39;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 31:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 34;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 32:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 6;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 33:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 7;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 34:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 2;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 35:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 5;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 32;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 36:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 3;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 37:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 4;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 38:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 9;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 39:
                switch(ch) {
                    case '0':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 8;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 11;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return IDENT; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 40:
                switch(ch) {
                    case '0':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 71;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 71;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return DECNUM; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 41:
                switch(ch) {
                    case '0':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 41;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        yylval.str_val=strdup(yytext);return DECNUM; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 42:
                switch(ch) {
                    case '<':
                        state = 67;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '=':
                        state = 66;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return '<'; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 43:
                switch(ch) {
                    case '=':
                        state = 65;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '>':
                        state = 70;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return '>'; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 44:
                switch(ch) {
                    case '=':
                        state = 64;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return '='; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 45:
                switch(ch) {
                    case '|':
                        state = 69;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        return '|'; 
                        state = 0;
                        yyleng = 0; memset(yytext, 0, sizeof(yytext));
                        break;
                }
                break;
            case 46:
                yyunput(ch);
                printf("存在愚蠢的东西"); 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 47:
                yyunput(ch);
                return '$'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 48:
                yyunput(ch);
                return '%'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 49:
                yyunput(ch);
                return '('; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 50:
                yyunput(ch);
                return ')'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 51:
                yyunput(ch);
                return '*';
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 52:
                yyunput(ch);
                return '+'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 53:
                yyunput(ch);
                return ','; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 54:
                yyunput(ch);
                return '-'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 55:
                yyunput(ch);
                return '/'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 56:
                yyunput(ch);
                return ';'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 57:
                yyunput(ch);
                return '['; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 58:
                yyunput(ch);
                return ']'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 59:
                yyunput(ch);
                return '^'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 60:
                yyunput(ch);
                return '{'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 61:
                yyunput(ch);
                return '}'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 62:
                yyunput(ch);
                return '~'; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 63:
                yyunput(ch);
                return AND; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 64:
                yyunput(ch);
                return EQ; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 65:
                yyunput(ch);
                return GE; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 66:
                yyunput(ch);
                return LE; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 67:
                yyunput(ch);
                return LSHIFT; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 68:
                yyunput(ch);
                return NE; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 69:
                yyunput(ch);
                return OR; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 70:
                yyunput(ch);
                return RSHIFT; 
                state = 0;
                yyleng = 0; memset(yytext, 0, sizeof(yytext));
                break;
            case 71:
                switch(ch) {
                    case '0':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '1':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '2':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '3':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '4':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '5':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '6':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '7':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '8':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case '9':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'A':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'B':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'C':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'D':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'E':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'F':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'G':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'H':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'I':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'J':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'K':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'L':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'M':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'N':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'O':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'P':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Q':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'R':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'S':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'T':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'U':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'V':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'W':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'X':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Y':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'Z':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'a':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'b':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'c':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'd':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'e':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'f':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'g':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'h':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'i':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'j':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'k':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'l':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'm':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'n':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'o':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'p':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'q':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'r':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 's':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 't':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'u':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'v':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'w':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'x':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'y':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    case 'z':
                        state = 10;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        printf("Lexical error: unexpected char '%c'\n", ch);
                        return -1;
                        break;
                }
                break;
            case 72:
                switch(ch) {
                    case '=':
                        state = 68;
                        if (yyleng < 1023) yytext[yyleng++] = ch;
                        break;
                    default:
                        yyunput(ch);
                        printf("Lexical error: unexpected char '%c'\n", ch);
                        return -1;
                        break;
                }
                break;
            default:
                return -1; // 未知状态错误
        }
    }
}
/* __SEULEX_YYLEX_END__ */
