%option noyywrap
%option nounput
%{
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

#include "parser.tab.hpp"


%}

%%
"-" { return *yytext; }
main {
	return main_token;
}

if {
	return if_token;
}

else {
       return else_token;
}

int {
	return int_token;	
}

return {
	return return_token;
}
[*;%,+=?{}()/><] {
            return *yytext;
}

[a-zA-Z_][a-zA-Z_0-9]* { 
  	yylval.s=new string(yytext);  
	return id_token; 
}

[-]?[0-9]+ {
	yylval.i= atoi(yytext);
	return num_token;
}
[ '\t''\n'] { }

%%
