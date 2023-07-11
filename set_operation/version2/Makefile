executable: parser.o lexer.o set.o
	g++ parser.o lexer.o set.o -o parser
set.o: set.cpp set.hpp
	g++ -c set.cpp -o set.o
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
	rm parser *.o	*.tab.* *.yy.* *.output
