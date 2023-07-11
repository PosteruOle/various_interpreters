%option noyywrap

%{
  #include <iostream>
  #include <vector>
  #include <string>

  using namespace std;
  #include "parser.tab.hpp"
%}


%%

"Graph"                  { return GRAPH; }
".addNode"               { return ADDNODE; }
".addEdge"               { return ADDEDGE; }
".showNeighbors"         { return SHOWNEIGHBORS; }
"exit"                   { return EXIT; }
[a-zA-Z_][a-zA-Z_0-9]*   { return ID; }
":="                     { return ASSIGN; }
[()<>;,]                 { return *yytext; }
[ \t\n]                  { }
. {
    cerr << "Lexical error! Unrecognised token: " << *yytext << endl;

  }


%%