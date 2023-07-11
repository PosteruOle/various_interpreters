%option noyywrap
%option noinput
%option nounput

%{
  #include <iostream>
  #include <cstdlib>
  #include <set>
  #include <string>
  
  using namespace std;
  
  #include "parser.tab.hpp"
  
%}


%%

UniversalSet   { return UNIVERSE; }
print          { return PRINT; }
check          { return CHECK; }
".size"        { return SIZE; }
[a-zA-Z]          { 
                 yylval.id=*yytext;
                 return ID; 
               }
[0-9]+         { 
                 yylval.x=atoi(yytext);
                 return NUMBER; 
               }
".."           { return ETC; }
"/\\"          { return INTERSECT; }
"\\/"          { return UNION; }
"\\"           { return DIFF; }
[.,(){}:;=<~]  { return *yytext; }
[ \n\t]        { }
.              {
                 cerr<< "Lexical error! Unrecognised token:" << *yytext << endl;
               }

%%
