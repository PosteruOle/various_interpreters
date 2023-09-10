izvrsni: parser.o lexer.o
	g++ -Wall lexer.o parser.o -o izvrsni

lexer.o: lex.yy.c 
	g++ -c -Wall lex.yy.c -o lexer.o

parser.o: parser.tab.hpp parser.tab.cpp 
	g++ -c -Wall parser.tab.cpp -o parser.o

lex.yy.c: lexer.l parser.tab.hpp
	flex lexer.l

parser.tab.hpp parser.tab.cpp: parser.ypp
	bison -dv parser.ypp

.PHONY: clean

clean:
	rm -rf ./izvrsni *.tab.* *.yy.* *.o *.output *.out
