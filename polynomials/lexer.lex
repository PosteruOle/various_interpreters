%option noyywrap
%{
    #include <iostream>
    #include <cstdlib>
    #include <string>
    #include <vector>

    using namespace std;

    #include "parser.tab.hpp"

%}

%%

[+-]?[0-9]+             { 
    yylval.x=atoi(yytext);
    return NUMBER; 
}
[a-zA-Z_][a-zA-Z_0-9]*  { 
    yylval.id=new string(yytext);
    return ID; 
}
[*<>,./()+'-]            { return *yytext; }
":="                    { return ASSIGN; }
"=="                    { return EQ; }
"!="                    { return EQ; }
">="                    { return GEQ; }
"["|"]"                 { return *yytext; }
"<="                    { return LEQ; }
[ \t]                   { }
[\n]                    { return *yytext; }
.                       { 
    cerr << "Lexical error! Unrecognized token: " << yytext << endl;
    exit(EXIT_FAILURE); 
}

%%