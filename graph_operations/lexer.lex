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
".info()"                { return INFO; }
".dfs"                   { return DFS; }
".bfs"                   { return BFS; }
".dijkstra"              { return DIJKSTRA; }
"exit"                   { return EXIT; }
[a-zA-Z_][a-zA-Z_0-9]*   { 
                           yylval.id=new string(yytext);
                           return ID; 
                         }
[1-9][0-9]*              { return NUMBER; }                         
":="                     { return ASSIGN; }
[()<>;,]                 { return *yytext; }
[ \t\n]                  { }
. {
    cerr << "Lexical error! Unrecognised token: " << *yytext << endl;
  }


%%
