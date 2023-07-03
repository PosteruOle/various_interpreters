izvrsni: parser.o lexer.o
	g++ parser.o lexer.o -o izvrsni
parser.o: parser.tab.cpp parser.tab.hpp
	g++ -c parser.tab.cpp -o parser.o
lexer.o: lex.yy.c parser.tab.hpp
	g++ -c lex.yy.c -o lexer.o 
lex.yy.c: lexer.lex parser.tab.hpp
	flex lexer.lex
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp
	

.PHONY: clean

clean:
	rm -f *.o lex.yy* parser.tab* parser.output izvrsni	
	
