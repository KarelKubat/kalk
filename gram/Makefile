
OBJ = parser.tab.o lex.yy.o yyerror.o

libgram.a: $(OBJ)
	ar rvs libgram.a $(OBJ)

parser.tab.cc: parser
	bison -d parser
	mv parser.tab.c parser.tab.cc
	mv parser.tab.h parser.h

lex.yy.cc: lexer
	flex lexer
	mv lex.yy.c lex.yy.cc

clean:
	rm -f $(OBJ) libgram.a

.cc.o:
	c++ -c $<
