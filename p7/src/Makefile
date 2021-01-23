CXX=g++
BIN=recursive_parser
INC=headers

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.c)

all: flex fin

fin: lex.yy.cpp tokens.cpp tipo.cpp simbolo.cpp parser.cpp main.cpp tablasimbolos.cpp
	$(CXX) -I$(INC) -g -o $(BIN) $^ 

%.o: %.c
	$(CXX) $@ -c $<

.PHONY: clean
clean :
	rm -f $(BIN) *.o lex.yy.cpp

.PHONY: flex
flex:
	flex lexer.lex
	mv lex.yy.c lex.yy.cpp
