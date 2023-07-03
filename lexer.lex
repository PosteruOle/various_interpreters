%option noyywrap

%{
  #include <iostream>
  #include <cstdlib>
  #include <vector>
  #include <string>
  #include <list>
  
  using namespace std;
  
  #include "parser.tab.hpp"
%}

%%

"stack"              { return STACK; }
"queue"              { return QUEUE; }
"print_stack"        { return PRINT_STACK; }
"print_queue"        { return PRINT_QUEUE; }
"push"               { return PUSH; }
"pop"                { return POP; }
"find"               { return FIND; }
"size"               { return SIZE; }
"peek"               { return PEEK; }
":="                 { return DODELA; }
"int"                { return NUMBER; }
_[a-zA-Z][a-zA-Z0-9_]*  { 
                          yylval.id=new string(yytext);
                          return ID; 
                        }
[-+<>,.;{}()/*]      { return *yytext; }
"=="                 { return EQ; }
"!="                 { return NEQ; }
[1-9][0-9]*          { 
                       yylval.x=atoi(yytext);
                       return BROJ; 
                     }
[ \t\n]              { }
.                    {
                       cout << "Leksicka greska! Neprepoznat token!\n";
                       exit(EXIT_FAILURE);
                     }


%%
