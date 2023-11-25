%option noyywrap
%{
    #include <iostream>
    #include <cstdlib>
    #include <string>
    #include <vector>
    #include <map>

    using namespace std;

    #include "parser.tab.hpp"

%}

%x comment1
%x comment2

%%

"/*"            { BEGIN(comment1); }
<comment1>[^\n] { }
<comment1>\n    { }
<comment1>"*/"  { BEGIN(INITIAL); }

"//"            { BEGIN(comment2); }
<comment2>.     { }
<comment2>\n    { BEGIN(INITIAL); }

[+-]?[0-9]+                { 
    yylval.x=atoi(yytext);
    return BROJ; 
}
"print_ALL"                { return PRINTALL; }
[a-zA-Z_][a-zA-Z_0-9]*     { 
    yylval.id=new string(yytext);
    return ID; 
}
[-+*\[\];,'()]             { return *yytext; }
":="                       { return DODELA; }
".*"                       { return PKM; }
[ \t]                      { }
[\n]                       { return *yytext; }
.                          { 
    cerr << "Lexical error! Unrecognized token: " << yytext << endl;
    exit(EXIT_FAILURE); 
}

%%